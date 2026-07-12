"""data/ の生データからメタ情報（タイトル・difficulty・出題元コンテスト）を読む。

build_vault.py（Vault 生成）と batch_tags.py（M3 のバッチ切り出し）の両方が使う。
M2 の成果物生成器に M3 が依存する形を避けるため、共有の読み取り層としてここに置く。
コードフェンスの整形も、コードを Markdown に埋める両者で共通なのでここに集める。
"""

from __future__ import annotations

import json
import math
import re

from common import DATA_DIR

# 拡張子 → Markdown（Prism）のシンタックスハイライト名。
FENCE_LANGUAGE = {
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

_BACKTICK_RUN_RE = re.compile(r"`+")


def fence_language(suffix: str) -> str:
    """拡張子に対応するハイライト名。未知なら空（フェンスに言語を書かない）。"""
    return FENCE_LANGUAGE.get(suffix, "")


def code_fence(code: str) -> str:
    """コード中の最長バックティック連よりも長いフェンスを返す。

    提出コードに ``` を含むコメントがあると、3 個固定のフェンスでは Markdown が途中で閉じて
    以降が壊れる。
    """
    longest = max((len(run.group()) for run in _BACKTICK_RUN_RE.finditer(code)), default=0)
    return "`" * max(3, longest + 1)


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
        raise SystemExit(f"{path} が無い。先に `python tools/fetch_meta.py` を実行すること。")
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
        raise SystemExit(f"{path} が無い。先に `python tools/fetch_meta.py` を実行すること。")
    return canonical_contests(json.loads(path.read_text(encoding="utf-8")))
