"""静的解析タグの単体テスト（ネットワーク不要）。

usage: python -m unittest discover -s tools -t tools -v
"""

from __future__ import annotations

import unittest

from classify import (
    auto_tags,
    classify,
    drop_redundant_parents,
    is_heuristic,
    is_material,
    strip_noise,
)


class StripNoiseTest(unittest.TestCase):
    def test_コメント中の語に反応しないよう剥がす(self):
        code = "int main() {} // dp で解いた\n/* priority_queue も試した */\n"
        stripped = strip_noise(code)
        self.assertNotIn("dp", stripped)
        self.assertNotIn("priority_queue", stripped)
        self.assertIn("int main()", stripped)

    def test_文字列リテラルの中身を消す(self):
        self.assertNotIn("dfs", strip_noise('cout << "dfs";'))

    def test_改行位置を変えない(self):
        code = "a\n/* x\ny\nz */\nb\n"
        self.assertEqual(strip_noise(code).count("\n"), code.count("\n"))

    def test_桁区切りを文字リテラルと誤認しない(self):
        # 1'000'000'007 の '000' をリテラル扱いで消すと MOD の検出が死ぬ。
        self.assertIn("1'000'000'007", strip_noise("const int M = 1'000'000'007;"))

    def test_文字リテラルは消す(self):
        self.assertNotIn("a", strip_noise("if (c == 'a') {}").split("==")[1])


class ClassifyTest(unittest.TestCase):
    def test_queueへのpushとpopを幅優先探索とみなす(self):
        code = "queue<int> q; q.push(s); while(!q.empty()){ int v=q.front(); q.pop(); }"
        self.assertIn("典型/探索/幅優先探索", classify(code))

    def test_priority_queueを幅優先探索と誤判定しない(self):
        # \bqueue< は priority_queue< に食い込まない（'_' の後には単語境界が無い）。
        code = "priority_queue<int> q; q.push(1); q.pop();"
        tags = classify(code)
        self.assertIn("典型/データ構造/priority_queue", tags)
        self.assertNotIn("典型/探索/幅優先探索", tags)

    def test_priority_queueがあるだけではダイクストラにしない(self):
        # 高精度・低再現率の方針。優先度付きキューは貪欲でも使う。
        code = "priority_queue<int> pq; pq.push(a[i]);"
        self.assertNotIn("典型/グラフ/ダイクストラ", classify(code))

    def test_priority_queueと距離配列の併用はダイクストラとみなす(self):
        code = "priority_queue<P> pq; vector<ll> dist(n, INF); dist[0] = 0;"
        self.assertIn("典型/グラフ/ダイクストラ", classify(code))

    def test_関数名がdijkstraならダイクストラ(self):
        self.assertIn("典型/グラフ/ダイクストラ", classify("void dijkstra(int s) {}"))

    def test_ワーシャルフロイドの内側1行を拾う(self):
        code = "d[i][j] = min(d[i][j], d[i][k] + d[k][j]);"
        self.assertIn("典型/グラフ/ワーシャルフロイド", classify(code))

    def test_chmin形のワーシャルフロイドも拾う(self):
        code = "chmin(dist[i][j], dist[i][k] + dist[k][j]);"
        self.assertIn("典型/グラフ/ワーシャルフロイド", classify(code))

    def test_累積和の骨格を拾う(self):
        self.assertIn("典型/数学/累積和", classify("s[i + 1] = s[i] + a[i];"))

    def test_別の配列への足し込みは累積和にしない(self):
        # 後方参照で同じ配列名・同じ添字であることを縛っている。
        self.assertNotIn("典型/数学/累積和", classify("s[i + 1] = t[i] + a[i];"))

    def test_ループ上限が2のn乗ならbit全探索(self):
        code = "for (int bit = 0; bit < (1 << n); bit++) {}"
        self.assertIn("典型/探索/bit全探索", classify(code))

    def test_単なるシフト演算はbit全探索にしない(self):
        self.assertNotIn("典型/探索/bit全探索", classify("int x = 1 << k;"))

    def test_range_forの後ろのシフトを巻き込まない(self):
        # `;` を含まない range-for を跨いで、無関係な `if (x < (1 << 20))` に届いてしまう穴。
        code = "for (auto e : g[v]) d[e] = 1;\nif (x < (1 << 20)) ok = true;"
        self.assertNotIn("典型/探索/bit全探索", classify(code))

    def test_repマクロ経由のbit全探索も拾う(self):
        # テンプレートの #define rep(i,n) 経由。実際にはこの書き方が主。
        self.assertIn("典型/探索/bit全探索", classify("rep(bit, 1 << n) { … }"))

    def test_dp配列をDPとみなす(self):
        self.assertIn("典型/DP", classify("vector<int> dp(n + 1); dp[0] = 1;"))

    def test_剰余演算をmod演算とみなす(self):
        self.assertIn("典型/数学/mod演算", classify("ans %= MOD; x = x % 998244353;"))

    def test_mint型の使用をmod演算とみなす(self):
        self.assertIn("典型/数学/mod演算", classify("mint ans = 0; vector<mint> dp(n);"))

    def test_方向配列を添字で引いていればグリッド(self):
        code = "int nx = x + dx[k], ny = y + dy[k];"
        self.assertIn("典型/データ構造/グリッド", classify(code))

    def test_dxだけではグリッドにしない(self):
        self.assertNotIn("典型/データ構造/グリッド", classify("int nx = x + dx[k];"))


class TemplateFalsePositiveTest(unittest.TestCase):
    """提出コードの先頭に常駐する共通テンプレートに反応しないことを固定する。

    テンプレートは問題と無関係に貼られているので、ここに反応するルールは全問題にタグを付ける。
    ルールを足すたびに再発しうる（実際、最初の実装では mod 検出 293 問中 213 問が誤検知だった）。
    """

    TEMPLATE = """
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;

int main(){
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
"""

    def test_テンプレートだけの提出にはタグが付かない(self):
        self.assertEqual(classify(self.TEMPLATE), [])

    def test_MODの宣言だけではmod演算にしない(self):
        self.assertNotIn("典型/数学/mod演算", classify(self.TEMPLATE))

    def test_方向配列の宣言だけではグリッドにしない(self):
        self.assertNotIn("典型/データ構造/グリッド", classify(self.TEMPLATE))

    def test_chminの定義だけではワーシャルフロイドにしない(self):
        self.assertNotIn("典型/グラフ/ワーシャルフロイド", classify(self.TEMPLATE))

    def test_テンプレートの上に本体があれば本体だけを見る(self):
        code = self.TEMPLATE + "\nvoid dfs(int v) {} \nans %= MOD;"
        tags = classify(code)
        self.assertIn("典型/探索/深さ優先探索", tags)
        self.assertIn("典型/数学/mod演算", tags)
        self.assertNotIn("典型/データ構造/グリッド", tags)

    def test_該当が無ければ空(self):
        self.assertEqual(classify("int main(){ int a, b; cin >> a >> b; }"), [])

    def test_タグの順序は実行ごとに揺れない(self):
        code = "vector<int> dp(n); set<int> s; queue<int> q; q.push(0); q.pop();"
        self.assertEqual(classify(code), classify(code))


class DropRedundantParentsTest(unittest.TestCase):
    """taxonomy.json の規範「最も具体的な葉だけを付ける」を静的解析にも効かせる。"""

    def test_子があれば親を落とす(self):
        self.assertEqual(
            drop_redundant_parents(["典型/グラフ", "典型/グラフ/ダイクストラ"]),
            ["典型/グラフ/ダイクストラ"],
        )

    def test_子が無ければ親を残す(self):
        # 裸の親タグは「そのカテゴリだが下位分類のどれでもない」を意味する枠として残す。
        self.assertEqual(drop_redundant_parents(["典型/グラフ"]), ["典型/グラフ"])

    def test_無関係なタグは消さない(self):
        # `典型/DP` は `典型/DPナントカ` の親ではない（区切りは "/" である）。
        self.assertEqual(
            drop_redundant_parents(["典型/DP", "典型/データ構造/set"]),
            ["典型/DP", "典型/データ構造/set"],
        )

    def test_bitDPの問題に親のDPを併記しない(self):
        code = "vector<int> dp(1 << n); dp[0] = 1; for (int s = 0; s < (1 << n); s++) dp[s] += 1;"
        tags = classify(code)
        self.assertIn("典型/DP/bitDP", tags)
        self.assertNotIn("典型/DP", tags)


class MaterialTest(unittest.TestCase):
    def test_APG4bは教材として典型分類しない(self):
        submission = {"contest_id": "APG4b", "problem_id": "APG4b_a"}
        code = "vector<int> dp(n); queue<int> q; q.push(0); q.pop();"
        self.assertTrue(is_material("APG4b"))
        self.assertEqual(auto_tags(submission, code), ["教材"])

    def test_tessoku_bookは典型分類の対象に残す(self):
        submission = {"contest_id": "tessoku-book", "problem_id": "tessoku_book_a"}
        self.assertFalse(is_material("tessoku-book"))
        self.assertIn("典型/DP", auto_tags(submission, "dp[i] = dp[i-1];"))


class HeuristicTest(unittest.TestCase):
    def test_AHCはヒューリスティックとして典型分類しない(self):
        # AHC はスコアを競うコンテストで、典型で分類する対象ではない。contest_id で機械的に
        # 決まるので、M3 の Claude に「貪欲か実装か」を判断させない。
        submission = {"contest_id": "ahc024", "problem_id": "ahc024_a"}
        code = "vector<int> dp(n); set<int> s; priority_queue<int> pq;"
        self.assertTrue(is_heuristic("ahc024"))
        self.assertEqual(auto_tags(submission, code), ["ヒューリスティック"])

    def test_abcはヒューリスティック扱いしない(self):
        self.assertFalse(is_heuristic("abc305"))


if __name__ == "__main__":
    unittest.main()
