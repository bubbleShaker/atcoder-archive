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
import re
from pathlib import Path

from classify import auto_tags
from common import (
    DATA_DIR,
    UnsafeIdError,
    language_name,
    pick_latest_ac,
    problem_code_path,
    write_atomic,
)

CODE_DIR = DATA_DIR / "code"
TAGS_PATH = DATA_DIR / "tags.json"  # M3 が作る確定タグ。無ければ静的解析だけで組む。
VAULT_DIR = DATA_DIR.parent / "vault"
NOTES_DIR = VAULT_DIR / "problems"

# AtCoder のコンテスト時刻は JST。epoch を UTC で解釈すると日付が 1 日ずれる。
JST = dt.timezone(dt.timedelta(hours=9))

# 拡張子 → Obsidian（Prism）のシンタックスハイライト名。
_FENCE_LANGUAGE = {
    ".cpp": "cpp",
    ".c": "c",
    ".cs": "csharp",
    ".java": "java",
    ".js": "javascript",
    ".ts": "typescript",
    ".py": "python",
    ".rs": "rust",
    ".go": "go",
    ".kt": "kotlin",
    ".rb": "ruby",
    ".sh": "bash",
}


def display_difficulty(raw: float | None) -> int | None:
    """problem-models.json の difficulty を AtCoder Problems の表示値に補正する。

    生の値は IRT の推定値で、易しい問題では負になる（abc138_a は -848）。そのまま使うと
    「diff 1000-1200 の壁」を見るための軸が壊れるので、AtCoder Problems と同じ式で
    400 未満を 0 以上に写す。
    """
    if raw is None:
        return None
    if raw >= 400:
        return round(raw)
    return round(400 / math.exp(1.0 - raw / 400))


def load_titles() -> dict[str, str]:
    """problem_id -> 問題名。

    problems.json の `title` は "E. Snuke the Cookie Picker" と接頭辞が付くので `name` を使う。
    `contest_id` も信用してはいけない（再出題コンテストの ID になっていることがある:
    abc305_c の contest_id は adt_medium_20231130_1）。URL は提出側の contest_id で組む。
    """
    path = DATA_DIR / "problems.json"
    if not path.exists():
        raise SystemExit(
            f"{path} が無い。先に `python tools/fetch_meta.py` を実行してタイトルを取得すること。"
        )
    problems = json.loads(path.read_text(encoding="utf-8"))
    return {problem["id"]: problem["name"] for problem in problems}


def load_difficulties() -> dict[str, dict]:
    path = DATA_DIR / "problem-models.json"
    if not path.exists():
        raise SystemExit(
            f"{path} が無い。先に `python tools/fetch_meta.py` を実行すること。"
        )
    return json.loads(path.read_text(encoding="utf-8"))


def canonical_contests(pairs: list[dict]) -> dict[str, str]:
    """problem_id -> 出題元コンテスト。

    1 問は複数のコンテストに属する（abc305_c は abc305 と ADT の 58 コンテストに属する）。
    提出時の contest_id をそのまま使うと、ADT や AtCoder Beginners Selection で解き直した
    124 問が adt_medium_… / abs 扱いになり、ABC・ARC 別の集計（M4）が壊れる。

    AtCoder の problem_id は出題元コンテストの ID を接頭辞に持つ（abc305_c → abc305、
    tessoku_book_a → tessoku-book）ので、候補の中から接頭辞一致するものを選ぶ。
    開催日時では選べない: abs・practice・tessoku-book は start_epoch_second が 0 で、
    「最も古いコンテスト」を採ると abc086_a の出題元が abs になってしまう。
    """
    canonical: dict[str, str] = {}
    for pair in sorted(pairs, key=lambda p: (p["problem_id"], p["contest_id"])):
        problem_id, contest_id = pair["problem_id"], pair["contest_id"]
        # 末尾の "_" まで含めて照合する。付けないと contest "abc30" が abc305_c に一致しうる。
        if problem_id.startswith(contest_id.replace("-", "_") + "_"):
            canonical.setdefault(problem_id, contest_id)
    return canonical


def load_canonical_contests() -> dict[str, str]:
    path = DATA_DIR / "contest-problem.json"
    if not path.exists():
        raise SystemExit(
            f"{path} が無い。先に `python tools/fetch_meta.py` を実行すること。"
        )
    return canonical_contests(json.loads(path.read_text(encoding="utf-8")))


def load_confirmed_tags() -> dict[str, list[str]]:
    """M3 が確定させたタグ。まだ無ければ空（静的解析の候補だけで Vault を組む）。"""
    if not TAGS_PATH.exists():
        return {}
    return json.loads(TAGS_PATH.read_text(encoding="utf-8"))


class Raw(str):
    """引用符を付けずにそのまま出す値。

    date を "2023-06-10" と引用符付きで書くと YAML の型は文字列になり、Dataview で
    日付として比較できない（M4 で「直近半年の diff 1000 台」のような絞り込みができなくなる）。
    裸で書けば YAML 1.2 が日付型として解釈する。
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
    if isinstance(value, bool):
        return "true" if value else "false"
    if isinstance(value, int):
        return str(value)
    if isinstance(value, list):
        return "[" + ", ".join(yaml_value(item) for item in value) + "]"
    return json.dumps(str(value), ensure_ascii=False)


_BACKTICK_RUN_RE = re.compile(r"`+")


def code_fence(code: str) -> str:
    """コード中の最長バックティック連よりも長いフェンスを返す。

    提出コードに ``` を含むコメントがあると、3 個固定のフェンスではノートが途中で閉じて
    以降が壊れる。
    """
    longest = max((len(run.group()) for run in _BACKTICK_RUN_RE.finditer(code)), default=0)
    return "`" * max(3, longest + 1)


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
        f"{fence}{_FENCE_LANGUAGE.get(extension, '')}\n{body}{fence}\n"
    )


def prune_stale_notes(notes_dir: Path, keep: set[Path]) -> list[Path]:
    """今回書き出さなかった古いノートを消す。

    タグ体系や対象範囲を変えて再生成したとき、前回の残骸が Vault に居座ると集計が狂う
    （vault/ は「捨てて再生成できる」ことに意味がある）。消すのは notes_dir 直下の .md だけで、
    Obsidian の設定（vault/.obsidian/）や手書きのノートには触れない。
    """
    removed = []
    for path in notes_dir.glob("*.md"):
        if path not in keep:
            path.unlink()
            removed.append(path)
    return removed


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, help="最初の N 問だけ生成（動作確認用）")
    args = parser.parse_args()

    submissions = json.loads((DATA_DIR / "submissions.json").read_text(encoding="utf-8"))
    targets = sorted(pick_latest_ac(submissions).values(), key=lambda s: s["problem_id"])
    if args.limit:
        targets = targets[: args.limit]

    titles = load_titles()
    models = load_difficulties()
    confirmed = load_confirmed_tags()
    contests = load_canonical_contests()

    NOTES_DIR.mkdir(parents=True, exist_ok=True)
    written: set[Path] = set()
    tag_counts: collections.Counter[str] = collections.Counter()
    missing_code: list[str] = []
    missing_title = missing_diff = untagged = resolved_elsewhere = 0

    for submission in targets:
        problem_id = submission["problem_id"]
        try:
            code_path = problem_code_path(CODE_DIR, submission)
        except UnsafeIdError:
            continue  # fetch_code.py が取得対象から外している ID。ノートも作らない。

        if not code_path.exists():
            missing_code.append(problem_id)
            continue

        code = code_path.read_text(encoding="utf-8", errors="replace")
        auto = auto_tags(submission, code)
        # 空リストで「典型なし」と確定させる余地を残すため、値ではなくキーの有無で判定する。
        is_confirmed = problem_id in confirmed
        tags = confirmed[problem_id] if is_confirmed else auto

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

        note_path = NOTES_DIR / f"{problem_id}.md"
        write_atomic(note_path, note)
        written.add(note_path)
        tag_counts.update(tags)
        if not tags:
            untagged += 1

    removed = prune_stale_notes(NOTES_DIR, written)

    print(f"生成 {len(written):,} ノート -> {NOTES_DIR}")
    if removed:
        print(f"  対象外になった古いノートを {len(removed):,} 件削除")
    if missing_code:
        print(
            f"  コード未取得のため除外 {len(missing_code)} 問: {missing_code[:5]}"
            "（`python tools/fetch_code.py` で取得できる）"
        )
    if missing_title:
        print(f"  タイトル不明 {missing_title} 問（problem_id で代用）")
    if missing_diff:
        print(f"  difficulty 不明 {missing_diff} 問（diff: null）")
    if resolved_elsewhere:
        print(
            f"  出題元コンテストに寄せ直し {resolved_elsewhere} 問"
            "（ADT や AtCoder Beginners Selection で解き直したぶん）"
        )

    print(f"\n  タグ確定済み（M3）: {sum(1 for s in targets if s['problem_id'] in confirmed):,} 問")
    print(f"  タグなし: {untagged:,} 問 … M3 で Claude が埋める")
    print("\n  タグ上位:")
    for tag, count in tag_counts.most_common(10):
        print(f"    {count:>5}  {tag}")


if __name__ == "__main__":
    main()
