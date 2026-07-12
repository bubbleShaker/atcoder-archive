"""提出コードから典型タグの「候補」を静的解析で抽出する。

**これはヒューリスティックであって、確定した分類ではない。** コードに現れる語や構文から
機械的に推測しているだけで、問題文は読んでいない。M3 で Claude が問題文とコードを読んで
確定させ、その結果が data/tags.json に入る（build_vault.py がそちらを優先する）。

方針は「高精度・低再現率」。証拠が確実なときだけタグを付け、迷ったら付けない。
priority_queue があるだけでダイクストラと決めつけるようなことはしない（優先度付きキューは
貪欲でも使う）。タグが付かない問題が多く残るのは想定どおりで、そこは M3 が埋める。

`典型/貪欲` と `典型/実装` は原理的にコードの見た目から判定できないため、ここでは扱わない。

**ルールは「宣言」ではなく「使用」を見ること。** 提出コードの先頭には共通テンプレートが貼られていて、
`vi dx = {-1,0,1,0}, dy = {0,1,0,-1};` `const ll MOD = 1000000007;` `using mint = modint998244353;`
が問題と無関係に常駐している。宣言に反応するルールを書くと、全問題にグリッドや mod のタグが付く
（実際に踏んだ: mod 検出 293 問のうち 213 問が宣言だけだった）。

usage: python tools/classify.py            # 全 AC コードにルールを当ててタグ分布を出す
"""

from __future__ import annotations

import argparse
import collections
import json
import re
from dataclasses import dataclass, field

from common import DATA_DIR, UnsafeIdError, pick_latest_ac, problem_code_path

CODE_DIR = DATA_DIR / "code"

# APG4b は C++ 入門教材（27 問）。文法練習であってアルゴリズムではないため、
# 典型分類の対象から外して #教材 だけを付ける。弱点分析の集計に混ざると分布が歪む。
MATERIAL_CONTESTS = {"APG4b"}
MATERIAL_TAG = "教材"

# AHC はヒューリスティックコンテスト（最適解ではなくスコアを競う）。典型で分類する対象では
# ないので #ヒューリスティック だけを付ける。contest_id の接頭辞で機械的に決まる規則なので、
# M3 の Claude の判断に委ねない（バッチごとに「貪欲」「シミュレーション」と割れるのを防ぐ）。
HEURISTIC_PREFIX = "ahc"
HEURISTIC_TAG = "ヒューリスティック"


@dataclass(frozen=True)
class Rule:
    """all_of の全てにマッチし、none_of のどれにもマッチしなければ tag を付ける。

    同じ tag を持つ Rule を複数並べてよい（OR になる）。「関数名が dijkstra」と
    「priority_queue と dist 配列の併用」のような、独立した根拠を別々に書くため。
    """

    tag: str
    all_of: tuple[str, ...]
    none_of: tuple[str, ...] = ()
    patterns: tuple[re.Pattern[str], ...] = field(init=False, repr=False)
    excludes: tuple[re.Pattern[str], ...] = field(init=False, repr=False)

    def __post_init__(self) -> None:
        object.__setattr__(self, "patterns", tuple(re.compile(p) for p in self.all_of))
        object.__setattr__(self, "excludes", tuple(re.compile(p) for p in self.none_of))

    def matches(self, code: str) -> bool:
        return all(p.search(code) for p in self.patterns) and not any(
            p.search(code) for p in self.excludes
        )


# 「配列 x の i+1 番目に i 番目を足し込む」= 累積和の骨格。添字と変数名を後方参照で縛る。
_CUMULATIVE_SUM = r"(\w+)\s*\[\s*(\w+)\s*\+\s*1\s*\]\s*=\s*\1\s*\[\s*\2\s*\]\s*[+|^]"
# d[i][j] = min(d[i][j], d[i][k] + d[k][j]) — ワーシャルフロイドの内側 1 行。
_WARSHALL_FLOYD = (
    r"(\w+)\s*\[\s*i\s*\]\s*\[\s*j\s*\]\s*=\s*min\s*\(\s*\1\s*\[\s*i\s*\]\s*\[\s*j\s*\]"
    r"\s*,\s*\1\s*\[\s*i\s*\]\s*\[\s*k\s*\]"
)
_WARSHALL_FLOYD_CHMIN = (
    r"chmin\s*\(\s*(\w+)\s*\[\s*i\s*\]\s*\[\s*j\s*\]\s*,\s*\1\s*\[\s*i\s*\]\s*\[\s*k\s*\]"
)
# for (int bit = 0; bit < (1 << n); ...) — ループ上限が 2^n なら bit 全探索。
# 括弧と改行を禁じて for ヘッダの中に閉じ込める。許すと `for (auto e : g[v]) …` の `)` を跨いで、
# 後続の無関係な `if (x < (1 << 20))` まで 1 つのマッチとして拾ってしまう。
_BIT_ENUMERATION = r"for\s*\([^;{}()\n]*;[^;{}()\n]*<\s*\(?\s*1\s*(?:LL|ll|u|U)?\s*<<"
# rep(bit, 1 << n) — 共通テンプレートの `#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)` 経由。
# 実際にはこちらの書き方が主で、素の for で書かれることは少ない。
_BIT_ENUMERATION_REP = r"\brep\s*\([^;{}()\n]*,\s*\(?\s*1\s*(?:LL|ll|u|U)?\s*<<"

_RULES: tuple[Rule, ...] = (
    # --- 探索 ---
    Rule("典型/探索/二分探索", (r"\b(?:lower_bound|upper_bound|binary_search)\s*\(",)),
    Rule("典型/探索/bit全探索", (_BIT_ENUMERATION,)),
    Rule("典型/探索/bit全探索", (_BIT_ENUMERATION_REP,)),
    Rule("典型/探索/順列全探索", (r"\bnext_permutation\s*\(",)),
    # queue<...> に push して pop する = BFS の骨格。
    # priority_queue は "_queue" の前が単語文字なので \bqueue には食われない。
    Rule("典型/探索/幅優先探索", (r"\bqueue\s*<", r"\.(?:push|emplace)\s*\(", r"\.pop\s*\(")),
    Rule("典型/探索/幅優先探索", (r"\bbfs\w*\s*\(",)),
    Rule("典型/探索/深さ優先探索", (r"\bdfs\w*\s*\(",)),
    # --- DP ---
    # dp という名前の配列/関数。DP の実装でこの名前を使わないことはまず無い。
    Rule("典型/DP", (r"\bdp\w*\s*[\[(]",)),
    Rule("典型/DP/bitDP", (r"\bdp\w*\s*[\[(][^;]*1\s*(?:LL|ll)?\s*<<",)),
    Rule("典型/DP/最長増加部分列", (r"\b(?:lis|LIS)\b",)),
    # --- グラフ ---
    Rule("典型/グラフ", (r"vector\s*<\s*vector\s*<[^;=]*>\s*>\s*(?:g|G|graph|adj|to|edge|edges)\b",)),
    Rule("典型/グラフ/ダイクストラ", (r"\bdijkstra\w*",)),
    Rule("典型/グラフ/ダイクストラ", (r"\bpriority_queue\s*<", r"\bdist\w*\s*[\[(]")),
    Rule("典型/グラフ/ワーシャルフロイド", (_WARSHALL_FLOYD,)),
    Rule("典型/グラフ/ワーシャルフロイド", (_WARSHALL_FLOYD_CHMIN,)),
    Rule("典型/グラフ/ワーシャルフロイド", (r"\b(?:warshall|floyd)\w*",)),
    Rule("典型/グラフ/UnionFind", (r"\b(?:dsu|DSU|UnionFind|union_?find|UnionFindTree)\b",)),
    Rule("典型/グラフ/UnionFind", (r"\bunite\s*\(",)),
    Rule("典型/グラフ/トポロジカルソート", (r"\b(?:topolog\w*|indeg\w*|in_degree\w*)",)),
    # --- 数学 ---
    Rule("典型/数学/GCD", (r"\b(?:__gcd|gcd|lcm)\s*\(",)),
    # 剰余「演算」があること。定数 MOD の宣言では駄目（テンプレートに常駐しているため）。
    Rule("典型/数学/mod演算", (r"%=?\s*(?:MOD\b|998244353|1000000007)",)),
    # ACL の modint も、型として使われて初めて mod 演算とみなす（`using mint = ...` は宣言）。
    Rule("典型/数学/mod演算", (r"\bmint\s+\w|<\s*mint\s*>|\bmint\s*\(",)),
    Rule("典型/数学/繰り返し二乗法", (r"\b(?:mod_?pow|pow_?mod|power_?mod|modexp)\b",)),
    Rule("典型/数学/素数", (r"\b(?:is_?prime\w*|sieve\w*|eratos\w*|primes?)\b",)),
    Rule("典型/数学/組合せ", (r"\b(?:nCr|nCk|comb\w*|binom\w*|factorial|kaijou)\b",)),
    # 階乗テーブル。factor[ / factors[（素因数分解）を巻き込まないよう綴りを限定する。
    Rule("典型/数学/組合せ", (r"\bfact(?:orial)?\s*\[",)),
    Rule("典型/数学/累積和", (_CUMULATIVE_SUM,)),
    Rule("典型/数学/累積和", (r"\b(?:cumsum|cum_sum|prefix_?sum|ruiseki\w*)\b",)),
    Rule("典型/数学/いもす法", (r"\bimos\b",)),
    # --- データ構造 ---
    Rule("典型/データ構造/set", (r"(?:\bset|\bmultiset|\bunordered_set)\s*<",)),
    Rule("典型/データ構造/map", (r"(?:\bmap|\bmultimap|\bunordered_map)\s*<",)),
    Rule("典型/データ構造/priority_queue", (r"\bpriority_queue\s*<",)),
    Rule("典型/データ構造/スタック", (r"\bstack\s*<",)),
    Rule("典型/データ構造/セグメント木", (r"\b(?:seg_?tree|segment_?tree|lazy_segtree)\b",)),
    Rule("典型/データ構造/BIT", (r"\b(?:fenwick\w*|BIT|binary_indexed\w*)\b",)),
    # 方向配列を「添字で引いている」こと = 4 近傍・8 近傍を実際に走査している証拠。
    # 宣言（`vi dx = {-1,0,1,0}, dy = {0,1,0,-1};`）で判定してはいけない。テンプレートに
    # 常駐しているので、グリッドと無関係な問題まで全て引っかかる。
    Rule("典型/データ構造/グリッド", (r"\bdx\s*\[", r"\bdy\s*\[")),
    # --- 文字列 ---
    Rule("典型/文字列/ランレングス", (r"\b(?:rle|run_?length)\b",)),
    Rule("典型/文字列/回文", (r"\b(?:palindrome\w*|is_?pal\b|kaibun)\b",)),
)

# コメントと文字列/文字リテラルを剥がすための一括パターン。
_NOISE_RE = re.compile(
    r'(?P<str>"(?:\\.|[^"\\\n])*")'
    # 文字リテラルは 1 文字ぶんだけ許す。`(?:\\.|[^'\\\n])*` と欲張ると、C++ の桁区切り
    # 1'000'000'007 の `'000'` をリテラルと誤認して MOD の検出を潰す。
    r"|(?P<chr>'(?:\\.|[^'\\\n])')"
    r"|(?P<line>//[^\n]*)"
    r"|(?P<block>/\*.*?\*/)",
    re.DOTALL,
)
_NON_NEWLINE_RE = re.compile(r"[^\n]")


def strip_noise(code: str) -> str:
    """コメントと文字列リテラルを取り除く。改行位置は変えない。

    文字列を空の文字列リテラルに、コメントを同じ長さの空白に置き換える。削除ではなく置換に
    しているのは、`a/b//c` のような並びでトークンが連結してしまうのを防ぐため。

    剥がさないと `cout << "dp"` のような出力や、コメント中の日本語解説にルールが反応する。
    """

    def replace(match: re.Match[str]) -> str:
        if match.lastgroup in ("str", "chr"):
            return '""'
        return _NON_NEWLINE_RE.sub(" ", match.group())

    return _NOISE_RE.sub(replace, code)


def drop_redundant_parents(tags: list[str]) -> list[str]:
    """子タグがあるなら親タグを落とす（`典型/DP` と `典型/DP/bitDP` なら後者だけ）。

    taxonomy.json の規範「最も具体的な葉だけを付ける」を静的解析にも効かせる。M3 で Claude が
    付ける確定タグだけ葉にしても、静的解析でタグが付いた問題はここの出力がそのまま Vault の
    tags になるので、規約が 2 系統に割れてしまう。

    親を落としても集計は失われない。Obsidian も Dataview も階層タグを前置一致で展開するため、
    `典型/DP/bitDP` は `典型/DP` の集計に自動で入る。裸の親タグは「そのカテゴリだが下位分類の
    どれでもない」を意味する枠として残す。
    """
    return [tag for tag in tags if not any(t.startswith(f"{tag}/") for t in tags)]


def classify(code: str) -> list[str]:
    """コードからタグ候補を返す。順序は _RULES の定義順（実行ごとに揺れない）。"""
    stripped = strip_noise(code)
    tags: list[str] = []
    for rule in _RULES:
        if rule.tag not in tags and rule.matches(stripped):
            tags.append(rule.tag)
    return drop_redundant_parents(tags)


def is_material(contest_id: str) -> bool:
    """典型分類の対象外とする教材か（APG4b）。"""
    return contest_id in MATERIAL_CONTESTS


def is_heuristic(contest_id: str) -> bool:
    """典型分類の対象外とするヒューリスティックコンテストか（AHC）。"""
    return contest_id.lower().startswith(HEURISTIC_PREFIX)


def rule_tags() -> frozenset[str]:
    """静的解析が付けうるタグの全集合。taxonomy.json との整合を外から検査するため。"""
    return frozenset(rule.tag for rule in _RULES) | {MATERIAL_TAG, HEURISTIC_TAG}


def auto_tags(submission: dict, code: str) -> list[str]:
    """1 提出に対する自動タグ。教材と AHC は典型分類せず除外タグだけを付ける。"""
    contest_id = submission["contest_id"]
    if is_material(contest_id):
        return [MATERIAL_TAG]
    if is_heuristic(contest_id):
        return [HEURISTIC_TAG]
    return classify(code)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, help="最初の N 問だけ（動作確認用）")
    args = parser.parse_args()

    submissions = json.loads((DATA_DIR / "submissions.json").read_text(encoding="utf-8"))
    targets = sorted(pick_latest_ac(submissions).values(), key=lambda s: s["problem_id"])
    if args.limit is not None:
        targets = targets[: args.limit]

    counts: collections.Counter[str] = collections.Counter()
    untagged = missing = 0

    for submission in targets:
        try:
            path = problem_code_path(CODE_DIR, submission)
        except UnsafeIdError:
            # 外部由来の ID。fetch_code.py も build_vault.py も除外している。
            # ここだけクラッシュさせない。
            missing += 1
            continue
        if not path.exists():
            missing += 1
            continue
        tags = auto_tags(submission, path.read_text(encoding="utf-8", errors="replace"))
        counts.update(tags)
        if not tags:
            untagged += 1

    total = len(targets) - missing
    print(f"対象 {total:,} 問（コード未取得 {missing} 問を除く）\n")
    for tag, count in counts.most_common():
        print(f"  {count:>5}  {tag}")
    print(f"\n  タグなし: {untagged:,} 問（{untagged / total:.0%}）… M3 で Claude が埋める")


if __name__ == "__main__":
    main()
