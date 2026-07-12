"""各問題の最新 AC 提出のソースコードを atcoder.jp から取得する。

1 req/秒 で回すため 1,700 問で 30 分ほどかかる。取得済みのファイルはスキップするので、
Ctrl-C で中断しても同じコマンドで再開できる。

usage: python tools/fetch_code.py [--limit N]
"""

from __future__ import annotations

import argparse
import collections
import json
from pathlib import Path

from common import (
    DATA_DIR,
    FetchError,
    UnsafeIdError,
    extract_submission_code,
    http_get,
    is_known_language,
    language_name,
    pick_latest_ac,
    problem_code_path,
    write_atomic,
)

CODE_DIR = DATA_DIR / "code"
FAILED_PATH = DATA_DIR / "failed.json"


def submission_url(submission: dict) -> str:
    return (
        f"https://atcoder.jp/contests/{submission['contest_id']}"
        f"/submissions/{submission['id']}"
    )


def remove_stale_siblings(path: Path) -> list[Path]:
    """同じ問題の、別拡張子で保存された古いファイルを消す。

    同じ問題を後から別言語で AC し直すと拡張子が変わり、旧ファイルが孤児として残る。
    1 問 1 ファイルの不変条件を保つ。

    unlink する破壊的処理なので、path.stem が glob のメタ文字（* ? [）を含まないことに
    依存している。これは problem_code_path の ID 検証が保証している（緩めると、
    関係ないファイルまで消える）。
    """
    removed = []
    for sibling in path.parent.glob(f"{path.stem}.*"):
        if sibling != path and sibling.suffix != ".part":
            sibling.unlink()
            removed.append(sibling)
    return removed


def split_unsafe(targets: list[dict]) -> tuple[list[dict], list[dict]]:
    """ファイルパスに使えない ID を持つ提出をあらかじめ分離する。

    不正な ID は取得ループに入る前に弾く。1 件の異常データで全体がクラッシュするより、
    その 1 件を除外して残りを取り切る方が、レジューム前提のバッチとして扱いやすい。
    """
    safe, unsafe = [], []
    for submission in targets:
        try:
            problem_code_path(CODE_DIR, submission)
            safe.append(submission)
        except UnsafeIdError:
            unsafe.append(submission)
    return safe, unsafe


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, help="最初の N 件だけ取得（動作確認用）")
    args = parser.parse_args()

    submissions = json.loads((DATA_DIR / "submissions.json").read_text(encoding="utf-8"))
    all_targets = sorted(
        pick_latest_ac(submissions).values(), key=lambda s: s["epoch_second"]
    )
    targets, unsafe = split_unsafe(all_targets)
    if unsafe:
        print(f"警告: 安全でない ID の提出 {len(unsafe)} 件を除外しました: "
              f"{[s['problem_id'] for s in unsafe[:5]]}\n")

    pending = [s for s in targets if not problem_code_path(CODE_DIR, s).exists()]
    already_done = len(targets) - len(pending)
    partial_run = args.limit is not None and args.limit < len(pending)
    if partial_run:
        pending = pending[: args.limit]

    print(f"対象 {len(targets):,} 問 / 取得済み {already_done:,} 問 / 今回取得 {len(pending):,} 問")
    if pending:
        print("想定所要時間: 約 {:.0f} 分（1 req/秒）。Ctrl-C で中断しても再開できます。\n".format(
            len(pending) / 60
        ))

    failures: list[dict] = []
    unknown_languages: collections.Counter[str] = collections.Counter()

    for index, submission in enumerate(pending, start=1):
        try:
            path = problem_code_path(CODE_DIR, submission)  # split_unsafe 済みなので通る
            page = http_get(submission_url(submission)).decode("utf-8")
            write_atomic(path, extract_submission_code(page))
            remove_stale_siblings(path)
            if not is_known_language(submission["language"]):
                unknown_languages[language_name(submission["language"])] += 1
            status = "ok"
        except (FetchError, UnicodeDecodeError) as error:
            failures.append({"submission": submission, "error": str(error)})
            status = f"FAILED: {error}"

        print(f"[{index:>4}/{len(pending)}] {submission['problem_id']:<20} {status}")

    if unknown_languages:
        print(f"\n拡張子が未定義で .txt に落とした言語: {dict(unknown_languages)}")

    if failures:
        write_atomic(FAILED_PATH, json.dumps(failures, ensure_ascii=False, indent=1))
        print(f"\n{len(failures)} 件失敗 -> {FAILED_PATH}（再実行すれば未取得ぶんだけ再試行します）")
    elif not partial_run:
        # 全件を走り切ったときだけ「失敗なし」を宣言できる。--limit 付きの成功で
        # 前回の失敗記録を消すと、状態表示が嘘になる。
        FAILED_PATH.unlink(missing_ok=True)
        print("\n完了。失敗なし。")
    else:
        print(f"\n--limit 実行のため打ち切り。残り {len(targets) - already_done - len(pending):,} 問。")


if __name__ == "__main__":
    main()
