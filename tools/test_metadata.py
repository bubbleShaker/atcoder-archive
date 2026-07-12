"""メタ情報の読み取り・整形の単体テスト（ネットワーク不要）。

usage: python -m unittest discover -s tools -t tools -v
"""

from __future__ import annotations

import unittest

from metadata import canonical_contests, code_fence, display_difficulty, fence_language


class CanonicalContestsTest(unittest.TestCase):
    def _pairs(self, *pairs):
        return [{"contest_id": c, "problem_id": p} for c, p in pairs]

    def test_再出題コンテストではなく出題元を選ぶ(self):
        # abc305_c は abc305 のほか ADT の 58 コンテストに属している。
        pairs = self._pairs(
            ("adt_medium_20241127_1", "abc305_c"),
            ("abc305", "abc305_c"),
            ("adt_all_20231130_1", "abc305_c"),
        )
        self.assertEqual(canonical_contests(pairs)["abc305_c"], "abc305")

    def test_開催が古いコンテストに引きずられない(self):
        # abs（AtCoder Beginners Selection）は start_epoch_second が 0 で「最古」だが、
        # abc086_a の出題元は abc086。
        pairs = self._pairs(("abs", "abc086_a"), ("abc086", "abc086_a"))
        self.assertEqual(canonical_contests(pairs)["abc086_a"], "abc086")

    def test_ハイフンとアンダースコアの違いを吸収する(self):
        pairs = self._pairs(("tessoku-book", "tessoku_book_a"))
        self.assertEqual(canonical_contests(pairs)["tessoku_book_a"], "tessoku-book")

    def test_接頭辞は区切りまで一致させる(self):
        # "abc30" が abc305_c の出題元になってはいけない。
        pairs = self._pairs(("abc30", "abc305_c"))
        self.assertNotIn("abc305_c", canonical_contests(pairs))

    def test_接頭辞が一致する候補が無ければ載せない(self):
        # 呼び出し側が提出時の contest_id で代用できるよう、当て推量はしない。
        pairs = self._pairs(("abs", "practice_1"))
        self.assertNotIn("practice_1", canonical_contests(self._pairs(("abs", "x_1"))))
        self.assertEqual(
            canonical_contests(pairs + self._pairs(("practice", "practice_1")))[
                "practice_1"
            ],
            "practice",
        )

class DisplayDifficultyTest(unittest.TestCase):
    def test_400以上はそのまま(self):
        self.assertEqual(display_difficulty(638.4), 638)

    def test_400未満は0以上に補正する(self):
        # 生の IRT 値は易しい問題で負になる（abc138_a は -848）。負の diff のまま集計すると
        # 「diff 1000-1200 の壁」を見る軸が壊れる。
        self.assertEqual(display_difficulty(-848), 18)
        self.assertGreater(display_difficulty(-2000), 0)

    def test_境界の400は補正の対象外(self):
        self.assertEqual(display_difficulty(400), 400)

    def test_モデルが無ければNone(self):
        self.assertIsNone(display_difficulty(None))

class CodeFenceTest(unittest.TestCase):
    def test_通常は3個(self):
        self.assertEqual(code_fence("int main() {}"), "```")

    def test_コード中のバックティックより長くする(self):
        # コード中に ``` があると、3 個固定のフェンスではノートが途中で閉じて以降が壊れる。
        code = "// ```\nint main() {}"
        fence = code_fence(code)
        self.assertEqual(fence, "````")
        self.assertNotIn(fence, code)

class FenceLanguageTest(unittest.TestCase):
    def test_拡張子からハイライト名を引く(self):
        self.assertEqual(fence_language(".cpp"), "cpp")
        self.assertEqual(fence_language(".cs"), "csharp")

    def test_未知の拡張子は空(self):
        # 言語名を書かずにフェンスするだけ。落ちるよりよい。
        self.assertEqual(fence_language(".unknown"), "")


if __name__ == "__main__":
    unittest.main()
