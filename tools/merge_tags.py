"""M3 の shard（data/tags.d/*.json）を検証して data/tags.json に集約する。

usage:
    python tools/merge_tags.py            # 検証して data/tags.json を書く
    python tools/merge_tags.py --dry-run  # 検証と統計だけ（書かない）

## ここが「Claude の出力が Vault に入る唯一の関門」である

shard を書くのは 18 個の独立したサブエージェントで、その出力は信用できない
（語彙外タグ・JSON 崩れ・他バッチの problem_id の混入・規約違反）。検証を build_vault 側に
分散させると、tags.json が壊れたまま Vault が組み上がって Dataview の集計が静かにズレる。
検証は全部ここに置き、通らないものは tags.json に到達させない。

## tags.json は shard から毎回まるごと組み直す

既存の tags.json に足し込むのではなく、shard 群だけを入力として全体を書き直す。
足し込みにすると、shard をやり直して問題を減らしたときに古いエントリが tags.json に
残り続け、どの shard にも由来しないタグが幽霊として生き残る。shard が真実の源。

## 検証ロジックは batch_tags から借りる（書き直さない）

バッチ境界・coverage・manifest 照合は batch_tags のものをそのまま使う。ここで書き直すと
「--list では済みなのに merge では未処理」のような 2 系統の判定が生まれ、どちらが正しいのか
誰も分からなくなる。
"""

from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from dataclasses import dataclass, field
from pathlib import Path

import batch_tags
from batch_tags import Batch, coverage_of, split_batches
from classify import drop_redundant_parents
from common import TAGS_PATH, write_atomic
from taxonomy import unknown_tags


class ShardError(ValueError):
    """shard の中身が信用できない。バッチをやり直すか、shard を手で直す。"""


@dataclass(frozen=True)
class ParsedShard:
    batch_id: str
    tags: dict[str, list[str]]
    pending: dict[str, str]
    # 「典型/DP と 典型/DP/桁DP を両方書いた」問題。意味は等価なので親を落として通すが、
    # 規約違反が常態化していないかを見るために件数を出す。
    normalized: tuple[str, ...] = ()


def parse_shard(raw: object, batch_id: str) -> ParsedShard:
    """shard データ（JSON をロードした結果）を検証して返す。IO はしない。

    エラーは 1 件目で投げず全部集めてから投げる。100 問のバッチで語彙外タグが 5 個あるとき、
    直す → 走らせる → 次のエラー、を 5 往復させないため。
    """
    if not isinstance(raw, dict):
        raise ShardError(f"{batch_id}: 最上位がオブジェクトでない")

    # batch キーの取り違えは「別のバッチのプロンプトを読んで、このファイルに書いた」を意味する。
    # 中身は妥当に見えるのに問題が丸ごと入れ替わっているので、coverage より前に弾く。
    declared = raw.get("batch")
    if declared is not None and declared != batch_id:
        raise ShardError(f"{batch_id}: batch が {declared!r} になっている（書き出し先の取り違え）")

    errors: list[str] = []
    tags: dict[str, list[str]] = {}
    normalized: list[str] = []

    raw_tags = raw.get("tags", {})
    if not isinstance(raw_tags, dict):
        raise ShardError(f"{batch_id}: tags がオブジェクトでない")
    for problem_id, value in raw_tags.items():
        if not isinstance(value, list) or not all(isinstance(tag, str) for tag in value):
            errors.append(f"  {problem_id}: タグが文字列のリストでない: {value!r}")
            continue
        unknown = unknown_tags(value)  # 既定は典型のみ。除外タグ（教材・ヒューリスティック）も弾く
        if unknown:
            errors.append(
                f"  {problem_id}: 語彙に無いタグ {unknown}"
                "（data/taxonomy.json に足すか、既存のタグに寄せること）"
            )
            continue
        # 重複と冗長な親は意味を変えずに直せる。落とすのは classify.py と同じ規約で
        # （葉だけを残す）、確定タグと auto_tags でタグの付け方が割れないようにする。
        deduped = list(dict.fromkeys(value))
        leaves = drop_redundant_parents(deduped)
        if leaves != deduped:
            normalized.append(problem_id)
        tags[problem_id] = leaves

    pending: dict[str, str] = {}
    raw_pending = raw.get("pending", {})
    if not isinstance(raw_pending, dict):
        raise ShardError(f"{batch_id}: pending がオブジェクトでない")
    for problem_id, reason in raw_pending.items():
        # 理由の無い保留は M3-4（問題文スクレイプの要否判断）の材料にならない。
        if not isinstance(reason, str) or not reason.strip():
            errors.append(f"  {problem_id}: pending の理由が空")
            continue
        pending[problem_id] = reason.strip()

    both = sorted(set(tags) & set(pending))
    if both:
        errors.append(f"  tags と pending の両方にある: {both}")

    if errors:
        raise ShardError(f"{batch_id}:\n" + "\n".join(errors))
    return ParsedShard(
        batch_id=batch_id,
        tags=tags,
        pending=pending,
        normalized=tuple(normalized),
    )


@dataclass(frozen=True)
class Merged:
    tags: dict[str, list[str]] = field(default_factory=dict)
    pending: dict[str, tuple[str, str]] = field(default_factory=dict)  # id -> (batch_id, 理由)
    normalized: tuple[str, ...] = ()


def merge_shards(shards: list[ParsedShard]) -> Merged:
    """shard 群を 1 つの確定タグ表にまとめる。problem_id の衝突は許さない。

    衝突は「バッチ境界がずれたまま走らせた」ことを意味する。片方を黙って採ると、どちらの
    判定が生き残ったのか後から追えない。coverage の unexpected でも検出できるが、こちらは
    バッチ定義を知らなくても（shard だけで）成立する不変条件なので独立に見る。
    """
    tags: dict[str, list[str]] = {}
    pending: dict[str, tuple[str, str]] = {}
    owner: dict[str, str] = {}
    normalized: list[str] = []
    for shard in sorted(shards, key=lambda s: s.batch_id):
        for problem_id in list(shard.tags) + list(shard.pending):
            previous = owner.get(problem_id)
            if previous is not None:
                raise ShardError(
                    f"{problem_id} が {previous} と {shard.batch_id} の両方にある"
                    "（バッチ境界がずれている。data/tags.d/ を捨てて切り直すこと）"
                )
            owner[problem_id] = shard.batch_id
        tags.update(shard.tags)
        pending.update({pid: (shard.batch_id, why) for pid, why in shard.pending.items()})
        normalized += shard.normalized
    # キー順を固定する。dict の挿入順のままだと shard を 1 つやり直すたびに tags.json の
    # 全体が並び替わり、diff が読めなくなる。
    return Merged(
        tags={pid: tags[pid] for pid in sorted(tags)},
        pending={pid: pending[pid] for pid in sorted(pending)},
        normalized=tuple(sorted(normalized)),
    )


@dataclass(frozen=True)
class Loaded:
    shards: list[ParsedShard] = field(default_factory=list)
    blocked: list[str] = field(default_factory=list)  # 書かれているが信用できない shard
    untouched: list[str] = field(default_factory=list)  # まだ書かれていないバッチ
    strays: list[str] = field(default_factory=list)  # どのバッチにも対応しない shard ファイル


def load_shards(batches: list[Batch]) -> Loaded:
    """済んだ shard を読む。壊れ・取りこぼしは blocked に、未着手は untouched に分ける。

    「まだ書かれていない」（作業が途中）と「書かれたが信用できない」（壊れている）を混ぜない。
    前者は正常な途中経過なので警告して先に進むが、後者は tags.json を汚すので止める。

    ファイルは 1 回だけ読む。済み判定（coverage_of）と中身の検証（parse_shard）で別々に
    読み直すと、両者が同じ内容を見た保証が無くなる。
    """
    loaded = Loaded()
    for batch in batches:
        if not batch.shard_path.exists():
            loaded.untouched.append(batch.batch_id)
            continue
        try:
            raw = json.loads(batch.shard_path.read_text(encoding="utf-8"))
        except json.JSONDecodeError as exc:
            loaded.blocked.append(f"{batch.batch_id}: JSON が壊れている: {exc}")
            continue

        result = coverage_of(raw, batch)
        if result.broken:
            loaded.blocked.append(f"{batch.batch_id}: {result.broken}")
            continue
        if not result.done:
            # プロンプトの truncate で後半が読まれなかった場合にここに来る。混ぜて通すと、
            # その問題は「未分類でもない・確定でもない」状態で永久に消える。
            detail = f"未記載 {len(result.missing)} 問 / 余分 {len(result.unexpected)} 問"
            if result.unexpected:
                detail += f"（余分: {', '.join(sorted(result.unexpected))}）"
            loaded.blocked.append(f"{batch.batch_id}: {detail}")
            continue

        try:
            loaded.shards.append(parse_shard(raw, batch.batch_id))
        except ShardError as exc:
            loaded.blocked.append(str(exc))

    # バッチ名と対応しない shard（`low-01.json` のようなゼロ埋め違い）は、どのバッチからも
    # 参照されないまま中身が捨てられる。該当バッチは「未処理」として出るので気付けるが、
    # 「書いたのに消えた」の原因がここだと分かるように名指しする。
    known = {batch.shard_path.name for batch in batches}
    loaded.strays.extend(
        path.name for path in batch_tags.existing_shards() if path.name not in known
    )
    return loaded


def render_tags_json(tags: dict[str, list[str]]) -> str:
    return json.dumps(tags, ensure_ascii=False, indent=2, sort_keys=True) + "\n"


def shrink_reason(new_count: int, tags_path: Path = TAGS_PATH) -> str | None:
    """確定タグが減る上書きを止める理由を返す（減らないなら None）。

    shard が真実の源である以上 tags.json は毎回組み直すが、**組み直しは減る方向にも効く**。
    現に、このツール群が指示する復旧手順がその地雷を踏む:

        18 バッチ完了（tags.json に 1,070 件）→ fetch_meta.py で difficulty が再推定される
        → check_manifest が「data/tags.d/ を捨てて切り直せ」と言う → 捨てる
        → merge_tags → shard 0 件 → tags.json = {} で全消し

    build_vault は黙って全問 auto タグに戻り、1,070 問ぶんの読解が消える。減る方向だけは
    人間の確認を挟む（build_vault.py の prune_blocker と同じ思想）。
    """
    if not tags_path.exists():
        return None
    try:
        previous = json.loads(tags_path.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return None  # 壊れた tags.json に守る価値は無い（上書きしてよい）
    old_count = len(previous) if isinstance(previous, dict) else 0
    if new_count >= old_count:
        return None
    return (
        f"確定タグが減る（{old_count} 問 → {new_count} 問）ので書かない。\n"
        "  shard を消したか、バッチをやり直して問題が減った可能性がある。\n"
        "  data/tags.d/ が揃っているかを確かめること: python tools/batch_tags.py --list\n"
        "  意図した縮小なら --force で上書きできる。"
    )


def print_stats(merged: Merged, out=sys.stdout) -> None:
    typed = {pid: tags for pid, tags in merged.tags.items() if tags}
    counts = Counter(tag for tags in typed.values() for tag in tags)
    print(f"確定 {len(merged.tags)} 問（典型あり {len(typed)} / 典型なし {len(merged.tags) - len(typed)}）", file=out)
    if merged.normalized:
        print(f"  親タグを落として正規化: {len(merged.normalized)} 問（葉だけを残す規約）", file=out)
    for tag, count in counts.most_common(15):
        print(f"  {count:>4}  {tag}", file=out)
    if len(counts) > 15:
        print(f"  … 他 {len(counts) - 15} 種", file=out)

    # pending は M3-4（問題文スクレイプの要否）の判断材料。件数だけでなく理由まで見せる。
    print(f"\n保留 {len(merged.pending)} 問", file=out)
    for problem_id, (batch_id, reason) in merged.pending.items():
        print(f"  {problem_id} [{batch_id}] {reason}", file=out)


def run(batches: list[Batch], *, dry_run: bool = False, force: bool = False, out=sys.stdout) -> None:
    """shard を集約して tags.json を書く。書けない理由があれば SystemExit で止める。

    「止める理由」を全部 SystemExit に畳んでいるのは、生のトレースバックで死ぬと対処が
    伝わらないため（batch_tags.check_manifest と同じ流儀）。
    """
    loaded = load_shards(batches)
    if loaded.blocked:
        raise SystemExit(
            "信用できない shard がある（tags.json は書いていない）:\n"
            + "\n".join(loaded.blocked)
            + "\n\n該当バッチをやり直すこと: python tools/batch_tags.py --show BATCH_ID"
        )

    try:
        merged = merge_shards(loaded.shards)
    except ShardError as exc:
        raise SystemExit(f"shard を集約できない（tags.json は書いていない）:\n  {exc}") from None

    blocker = shrink_reason(len(merged.tags), TAGS_PATH)
    if blocker and not force and not dry_run:
        raise SystemExit(blocker)

    if not dry_run:
        write_atomic(TAGS_PATH, render_tags_json(merged.tags))

    header = f"shard {len(loaded.shards)} / {len(batches)} バッチ"
    print(header + ("（--dry-run: 書いていない）" if dry_run else ""), file=out)
    if loaded.untouched:
        print(f"⚠ 未処理 {len(loaded.untouched)} バッチ: {', '.join(loaded.untouched)}", file=out)
    if loaded.strays:
        print(f"⚠ バッチに対応しない shard: {', '.join(loaded.strays)}（中身は無視した）", file=out)
    if blocker and dry_run:
        print(f"⚠ このまま書くと止まる: {blocker.splitlines()[0]}", file=out)
    print(file=out)
    print_stats(merged, out=out)
    if not dry_run:
        print(f"\n{TAGS_PATH.as_posix()} を書いた。次: python tools/build_vault.py", file=out)


def main() -> None:
    # Windows の既定 cp932 では日本語もタグも print できずに落ちる（batch_tags.py と同じ理由）。
    sys.stdout.reconfigure(encoding="utf-8")
    sys.stderr.reconfigure(encoding="utf-8")

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--dry-run", action="store_true", help="検証と統計だけ。tags.json を書かない")
    parser.add_argument(
        "--force", action="store_true", help="確定タグが減る上書きを許す（shard を意図的に減らした場合）"
    )
    args = parser.parse_args()

    problems, _ = batch_tags.collect_untagged()
    batches = split_batches(problems)
    # バッチ境界のドリフト検知。ここを通らないと集約もできない。--dry-run では照合だけして
    # 指紋は書かない（「書かない」と宣言したコマンドが検知の記録を更新してはいけない）。
    batch_tags.check_manifest(batches, persist=not args.dry_run)

    run(batches, dry_run=args.dry_run, force=args.force)


if __name__ == "__main__":
    main()
