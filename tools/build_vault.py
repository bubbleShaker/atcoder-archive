"""data/ の生データから Obsidian Vault（1 問 1 ノート）を生成する。

vault/ は**派生物**である。ここで書き出すものは全て data/ から再構成でき、捨てて作り直せる。
生データ（data/）には一切書き戻さない。分類をやり直しても 1,716 問の再ダウンロードが
走らないようにするのが、この repo の骨格（PLAN.md 参照）。

何度実行しても同じ結果になる（前回生成して今回の対象から外れたノートは削除する）。

タグの出どころは 2 つある:
- 静的解析（classify.py）… 常に auto_tags に入る。ヒューリスティックな候補。
- data/tags.json … M3 で Claude が問題文まで読んで確定させたタグ。あればこちらを tags にする。
  M3 の成果を vault/ ではなく data/ 側に置くことで、vault/ を「捨てられる派生物」のまま保つ。

usage: python tools/build_vault.py [--limit N]
"""

from __future__ import annotations

import argparse
import collections
import datetime as dt
import json
import math
from pathlib import Path

from classify import auto_tags
from common import (
    DATA_DIR,
    TAGS_PATH,
    UnsafeIdError,
    ensure_inside,
    ensure_safe_id,
    language_name,
    pick_latest_ac,
    problem_code_path,
    write_atomic,
)
from metadata import (
    FENCE_LANGUAGE,
    code_fence,
    display_difficulty,
    load_canonical_contests,
    load_difficulties,
    load_titles,
)

CODE_DIR = DATA_DIR / "code"  # TAGS_PATH（M3 の確定タグ）は common に置いてある
VAULT_DIR = DATA_DIR.parent / "vault"
NOTES_DIR = VAULT_DIR / "problems"

# AtCoder のコンテスト時刻は JST。epoch を UTC で解釈すると日付が 1 日ずれる。
JST = dt.timezone(dt.timedelta(hours=9))


def validate_confirmed_tags(raw: object) -> dict[str, list[str]]:
    """tags.json が {problem_id: [タグ, …]} の形であることを確かめる。

    形が違っても frontmatter は壊れない（yaml_value が引用符で囲む）が、`tags: "典型/DP"` と
    スカラーで出て Dataview の集計が**静かに**壊れる。黙って進むより落ちる方がよい。
    """
    if not isinstance(raw, dict):
        raise SystemExit(f"{TAGS_PATH}: 最上位は問題 ID をキーとするオブジェクトであること")
    for problem_id, tags in raw.items():
        if not isinstance(tags, list) or not all(isinstance(tag, str) for tag in tags):
            raise SystemExit(f"{TAGS_PATH}: {problem_id} のタグが文字列のリストでない: {tags!r}")
    return raw


def load_confirmed_tags() -> dict[str, list[str]]:
    """M3 が確定させたタグ。まだ無ければ空（静的解析の候補だけで Vault を組む）。"""
    if not TAGS_PATH.exists():
        return {}
    return validate_confirmed_tags(json.loads(TAGS_PATH.read_text(encoding="utf-8")))


class Raw(str):
    """引用符を付けずにそのまま出す値。

    date を "2023-06-10" と引用符付きで書くと YAML の型は文字列になり、Dataview で
    日付として比較できない（M4 で「直近半年の diff 1000 台」のような絞り込みができなくなる）。
    裸で書けば YAML 1.2 が日付型として解釈する。

    **外部由来の値を包んではいけない。** 引用符もエスケープも通さないので、包んだ瞬間に
    frontmatter インジェクションの経路になる。こちらで組み立てた値だけを包むこと。
    """


def yaml_value(value: object) -> str:
    """frontmatter に埋める YAML スカラー/フロー列を作る。

    文字列は json.dumps で囲む。JSON の文字列は YAML 1.2 の二重引用符スカラーとして妥当なので、
    引用符・コロン・バックスラッシュを含む問題名（`"Yes" or "No"` のような題名が実在する）を
    自前でエスケープせずに済む。
    """
    if value is None:
        return "null"
    if isinstance(value, Raw):  # str のサブクラスなので str より先に判定する
        return str(value)
    if isinstance(value, bool):  # bool は int のサブクラスなので int より先に判定する
        return "true" if value else "false"
    if isinstance(value, float) and not math.isfinite(value):
        # str(nan) は "nan"。YAML の float リテラルは ".nan" なので、そのまま書くと文字列に
        # なって静かに型が崩れる。ここに来る値は無いはずなので、黙って通さず落とす。
        raise ValueError(f"frontmatter に書けない数値: {value!r}")
    if isinstance(value, (int, float)):
        return str(value)
    if isinstance(value, list):
        return "[" + ", ".join(yaml_value(item) for item in value) + "]"
    return json.dumps(str(value), ensure_ascii=False)


def render_note(
    submission: dict,
    *,
    contest: str,
    title: str,
    difficulty: int | None,
    experimental: bool,
    tags: list[str],
    auto: list[str],
    tag_source: str,
    code: str,
    extension: str,
) -> str:
    problem_id = submission["problem_id"]
    url = f"https://atcoder.jp/contests/{contest}/tasks/{problem_id}"
    # 提出ページだけは提出時のコンテスト配下にある（ADT で解き直した提出は ADT 側にしか無い）。
    submission_url = (
        f"https://atcoder.jp/contests/{submission['contest_id']}"
        f"/submissions/{submission['id']}"
    )
    date = dt.datetime.fromtimestamp(submission["epoch_second"], JST).date().isoformat()

    # 構造化データは全て frontmatter に置く。Dataview（M4）で「典型 × difficulty」の表を
    # 組めるようにするため。本文に散らすと集計できない。
    fields = {
        "problem_id": problem_id,
        "contest": contest,
        "title": title,
        "diff": difficulty,
        "diff_experimental": experimental,
        "result": submission["result"],
        "date": Raw(date),
        "lang": language_name(submission["language"]),
        "length": submission["length"],
        "exec_time": submission["execution_time"],
        "tags": tags,
        "auto_tags": auto,
        "tag_source": tag_source,
        "url": url,
    }
    frontmatter = "\n".join(f"{key}: {yaml_value(value)}" for key, value in fields.items())

    fence = code_fence(code)
    body = code if code.endswith("\n") else code + "\n"
    return (
        f"---\n{frontmatter}\n---\n\n"
        f"# {title}\n\n"
        f"[問題ページ]({url}) · [提出]({submission_url})\n\n"
        f"## 提出コード\n\n"
        f"{fence}{FENCE_LANGUAGE.get(extension, '')}\n{body}{fence}\n"
    )


def prune_blocker(*, limit: int | None, written: int, missing_code: int) -> str | None:
    """古いノートを消してはいけない理由。消してよければ None。

    prune は「今回書かなかったノート = 対象外になったノート」という前提に立つ。全件を走り切って
    いないとこの前提が崩れ、消してはいけないノートまで消える:
    - `--limit 5` は 5 問しか書かないので、残り 1,711 枚が「対象外」に見えてしまう。
      動作確認のつもりで打った --limit が Vault を全消しする。
    - コードが未取得の問題があるとき（fetch_code.py が途中までしか走っていない）。
    - 書き出しが 0 件のとき。submissions.json が壊れている・空・別ユーザーのもの、という
      事故が実際に起こりうる（fetch_meta.py はページングを打ち切ると不完全なファイルを書く）。

    どうしても消したいときは --prune で上書きできる（恒久的に取得できない提出が残ったときの脱出口）。
    """
    if limit is not None:
        return "--limit 付きの部分実行"
    if written == 0:
        return "書き出したノートが 0 件（submissions.json が空か壊れている可能性）"
    if missing_code:
        return f"コード未取得の問題が {missing_code} 問（fetch_code.py が未完了の可能性）"
    return None


def prune_stale_notes(notes_dir: Path, keep: set[Path]) -> list[Path]:
    """今回書き出さなかった古いノートを消す。

    タグ体系や対象範囲を変えて再生成したとき、前回の残骸が Vault に居座ると集計が狂う
    （vault/ は「捨てて再生成できる」ことに意味がある）。

    notes_dir 直下の .md は全て build_vault.py の生成物とみなして消す（手書きのノートを
    ここに置いてはいけない）。write_atomic が中断されて残った .md.part も掃除する。
    Obsidian の設定（vault/.obsidian/）やサブディレクトリ、他の拡張子には触れない。
    呼ぶ前に prune_blocker で全件実行かどうかを確かめること。
    """
    removed = []
    for path in sorted(notes_dir.glob("*.md")) + sorted(notes_dir.glob("*.md.part")):
        if path not in keep and path.is_file():
            path.unlink()
            removed.append(path)
    return removed


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, help="最初の N 問だけ生成（動作確認用）")
    parser.add_argument(
        "--prune",
        action="store_true",
        help="全件を走り切っていなくても、対象外のノートを削除する（既定では見送る）",
    )
    args = parser.parse_args()

    submissions = json.loads((DATA_DIR / "submissions.json").read_text(encoding="utf-8"))
    targets = sorted(pick_latest_ac(submissions).values(), key=lambda s: s["problem_id"])
    if args.limit is not None:
        targets = targets[: args.limit]

    titles = load_titles()
    models = load_difficulties()
    confirmed = load_confirmed_tags()
    contests = load_canonical_contests()

    NOTES_DIR.mkdir(parents=True, exist_ok=True)
    written: set[Path] = set()
    tag_counts: collections.Counter[str] = collections.Counter()
    missing_code: list[str] = []
    unsafe_ids: list[str] = []
    confirmed_count = missing_title = missing_diff = untagged = resolved_elsewhere = 0

    for submission in targets:
        problem_id = submission["problem_id"]
        try:
            code_path = problem_code_path(CODE_DIR, submission)
            # problem_id は kenkoooo API 由来（= 自分の制御下にない値）。ノートのパスも
            # コードのパスと同じ検証を通す。problem_code_path の副作用に安全性を頼ると、
            # 「コードが無くてもノートは作る」に変えた瞬間にパストラバーサルが復活する。
            note_path = ensure_inside(
                NOTES_DIR, NOTES_DIR / f"{ensure_safe_id(problem_id, 'problem_id')}.md"
            )
        except UnsafeIdError:
            unsafe_ids.append(problem_id)
            continue

        if not code_path.exists():
            missing_code.append(problem_id)
            continue

        code = code_path.read_text(encoding="utf-8", errors="replace")
        auto = auto_tags(submission, code)
        # 空リストで「典型なし」と確定させる余地を残すため、値ではなくキーの有無で判定する。
        is_confirmed = problem_id in confirmed
        tags = confirmed[problem_id] if is_confirmed else auto
        confirmed_count += is_confirmed

        title = titles.get(problem_id)
        if title is None:
            missing_title += 1
            title = problem_id

        model = models.get(problem_id, {})
        difficulty = display_difficulty(model.get("difficulty"))
        if difficulty is None:
            missing_diff += 1

        # 出題元が引けなければ提出時のコンテストで代用する（そこにも問題ページはある）。
        contest = contests.get(problem_id, submission["contest_id"])
        if contest != submission["contest_id"]:
            resolved_elsewhere += 1

        note = render_note(
            submission,
            contest=contest,
            title=title,
            difficulty=difficulty,
            experimental=bool(model.get("is_experimental", False)),
            tags=tags,
            auto=auto,
            tag_source="claude" if is_confirmed else "auto",
            code=code,
            extension=code_path.suffix,
        )

        write_atomic(note_path, note)
        written.add(note_path)
        tag_counts.update(tags)
        if not tags:
            untagged += 1

    blocker = prune_blocker(
        limit=args.limit, written=len(written), missing_code=len(missing_code)
    )
    removed = prune_stale_notes(NOTES_DIR, written) if args.prune or not blocker else []

    print(f"生成 {len(written):,} ノート -> {NOTES_DIR}")
    if removed:
        print(f"  対象外になった古いノートを {len(removed):,} 件削除")
    elif blocker:
        print(f"  古いノートの削除は見送った（{blocker}）。消すなら --prune")
    if missing_code:
        print(
            f"  コード未取得のため除外 {len(missing_code)} 問: {missing_code[:5]}"
            "（`python tools/fetch_code.py` で取得できる）"
        )
    if unsafe_ids:
        print(f"  安全でない ID のため除外 {len(unsafe_ids)} 問: {unsafe_ids[:5]}")
    if missing_title:
        print(f"  タイトル不明 {missing_title} 問（problem_id で代用）")
    if missing_diff:
        print(f"  difficulty 不明 {missing_diff} 問（diff: null）")
    if resolved_elsewhere:
        print(
            f"  出題元コンテストに寄せ直し {resolved_elsewhere} 問"
            "（ADT や AtCoder Beginners Selection で解き直したぶん）"
        )

    print(f"\n  タグ確定済み（M3）: {confirmed_count:,} 問")
    print(f"  タグなし: {untagged:,} 問 … M3 で Claude が埋める")
    print("\n  タグ上位:")
    for tag, count in tag_counts.most_common(10):
        print(f"    {count:>5}  {tag}")


if __name__ == "__main__":
    main()
