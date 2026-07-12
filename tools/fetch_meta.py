"""提出メタデータ・difficulty・問題タイトルを kenkoooo AtCoder Problems から取得する。

ソースコード本文はここでは取らない（API に含まれない）。本文は fetch_code.py が
atcoder.jp から取得する。

usage: python tools/fetch_meta.py [--user Coji]
"""

from __future__ import annotations

import argparse
import collections
import datetime as dt
import json
import sys
from typing import Callable

from common import DATA_DIR, http_get, write_atomic

SUBMISSIONS_API = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"
PROBLEM_MODELS_URL = "https://kenkoooo.com/atcoder/resources/problem-models.json"
PROBLEMS_URL = "https://kenkoooo.com/atcoder/resources/problems.json"
# 問題がどのコンテストで出題されたか。1 問が複数コンテストに属する（ABC の問題は
# ADT でも再出題される）ので、出題元を特定するのに要る。build_vault.py が使う。
CONTEST_PROBLEM_URL = "https://kenkoooo.com/atcoder/resources/contest-problem.json"

# v3 API は 1 リクエストにつき最大 500 件しか返さない。
PAGE_SIZE = 500

Fetcher = Callable[[str], bytes]


def fetch_all_submissions(user: str, fetch: Fetcher = http_get) -> list[dict]:
    """全提出をページングして取得する。

    v3 API は from_second 以降を古い順に最大 500 件返す。同じ秒に複数の提出があると
    from_second を +1 して進めた瞬間に取りこぼすため、「最後の提出と同じ秒から取り直し、
    重複は id で弾く」方式にしている。

    fetch を差し替えられるようにしてあるのは、ページング境界（500 件ちょうど・同一秒跨ぎ・
    空応答）をネットワーク無しでテストするため。
    """
    submissions: list[dict] = []
    seen_ids: set[int] = set()
    from_second = 0

    while True:
        url = f"{SUBMISSIONS_API}?user={user}&from_second={from_second}"
        page = json.loads(fetch(url))
        if not page:
            break

        added = 0
        for submission in page:
            if submission["id"] not in seen_ids:
                seen_ids.add(submission["id"])
                submissions.append(submission)
                added += 1

        if len(page) < PAGE_SIZE:
            break
        if added == 0:
            # 1 秒間に PAGE_SIZE 件以上の提出があると from_second が前進せず、
            # 同じページを永久に取り続けてしまう。新規ゼロなら打ち切る。
            # ここに来た時点でデータは不完全なので、黙って成功扱いにはしない。
            print(
                f"警告: from_second={from_second} で新規提出が 0 件のため打ち切りました。"
                "データが不完全な可能性があります。",
                file=sys.stderr,
            )
            break

        from_second = page[-1]["epoch_second"]

    submissions.sort(key=lambda s: s["epoch_second"])
    return submissions


def summarize(submissions: list[dict]) -> str:
    accepted = [s for s in submissions if s["result"] == "AC"]
    unique_problems = {s["problem_id"] for s in accepted}
    languages = collections.Counter(s["language"].split(" (")[0] for s in submissions)
    first = dt.datetime.fromtimestamp(submissions[0]["epoch_second"]).date()
    last = dt.datetime.fromtimestamp(submissions[-1]["epoch_second"]).date()

    return "\n".join(
        [
            f"  全提出      : {len(submissions):,} 件",
            f"  AC 提出     : {len(accepted):,} 件",
            f"  ユニーク AC : {len(unique_problems):,} 問",
            f"  期間        : {first} 〜 {last}",
            f"  言語        : {dict(languages.most_common(5))}",
        ]
    )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--user", default="Coji")
    args = parser.parse_args()

    DATA_DIR.mkdir(parents=True, exist_ok=True)

    print(f"提出メタデータを取得中（user={args.user}）…")
    submissions = fetch_all_submissions(args.user)
    if not submissions:
        sys.exit(f"提出が 1 件も見つからない（user={args.user} は存在する？）")

    submissions_path = DATA_DIR / "submissions.json"
    write_atomic(submissions_path, json.dumps(submissions, ensure_ascii=False, indent=1))
    print()
    print(summarize(submissions))
    print(f"  -> {submissions_path}")

    print("\ndifficulty（problem-models.json）を取得中 …")
    models_path = DATA_DIR / "problem-models.json"
    raw = http_get(PROBLEM_MODELS_URL)
    write_atomic(models_path, raw)
    print(f"  {len(json.loads(raw)):,} 問ぶんの推定 difficulty -> {models_path}")

    print("\n問題タイトル（problems.json）を取得中 …")
    problems_path = DATA_DIR / "problems.json"
    raw = http_get(PROBLEMS_URL)
    write_atomic(problems_path, raw)
    print(f"  {len(json.loads(raw)):,} 問ぶんのタイトル -> {problems_path}")

    print("\nコンテストと問題の対応（contest-problem.json）を取得中 …")
    contest_problem_path = DATA_DIR / "contest-problem.json"
    raw = http_get(CONTEST_PROBLEM_URL)
    write_atomic(contest_problem_path, raw)
    print(f"  {len(json.loads(raw)):,} 組の対応 -> {contest_problem_path}")


if __name__ == "__main__":
    main()
