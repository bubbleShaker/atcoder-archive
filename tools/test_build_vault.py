"""Vault 生成の単体テスト（ネットワーク不要）。

usage: python -m unittest discover -s tools -t tools -v
"""

from __future__ import annotations

import tempfile
import unittest
from pathlib import Path

from build_vault import (
    Raw,
    canonical_contests,
    code_fence,
    display_difficulty,
    prune_blocker,
    prune_stale_notes,
    render_note,
    validate_confirmed_tags,
    yaml_value,
)


def submission(problem_id="abc305_c", contest_id="abc305", epoch=1686401043):
    return {
        "id": 42146394,
        "problem_id": problem_id,
        "contest_id": contest_id,
        "epoch_second": epoch,
        "result": "AC",
        "language": "C++ 20 (gcc 12.2)",
        "length": 1270,
        "execution_time": 12,
    }


def note(submitted=None, **overrides) -> str:
    kwargs = {
        "contest": "abc305",
        "title": "Snuke the Cookie Picker",
        "difficulty": 638,
        "experimental": False,
        "tags": ["典型/探索/幅優先探索"],
        "auto": ["典型/探索/幅優先探索"],
        "tag_source": "auto",
        "code": "int main() {}\n",
        "extension": ".cpp",
    }
    kwargs.update(overrides)
    return render_note(submitted or submission(), **kwargs)


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


class YamlValueTest(unittest.TestCase):
    def test_引用符やコロンを含むタイトルを壊さない(self):
        # AtCoder には `"Yes" or "No"` のような題名が実在する。
        self.assertEqual(yaml_value('"Yes" or "No": 1'), '"\\"Yes\\" or \\"No\\": 1"')

    def test_日本語をエスケープしない(self):
        self.assertEqual(yaml_value("典型/DP"), '"典型/DP"')

    def test_リストはフロー列にする(self):
        self.assertEqual(yaml_value(["典型/DP", "教材"]), '["典型/DP", "教材"]')

    def test_空リスト(self):
        self.assertEqual(yaml_value([]), "[]")

    def test_NoneとboolはYAMLのリテラル(self):
        self.assertEqual(yaml_value(None), "null")
        self.assertEqual(yaml_value(True), "true")
        self.assertEqual(yaml_value(False), "false")

    def test_Rawは引用符を付けない(self):
        # 引用符を付けると YAML の型が文字列になり、Dataview で日付比較できない。
        self.assertEqual(yaml_value(Raw("2023-06-10")), "2023-06-10")


class CodeFenceTest(unittest.TestCase):
    def test_通常は3個(self):
        self.assertEqual(code_fence("int main() {}"), "```")

    def test_コード中のバックティックより長くする(self):
        # コード中に ``` があると、3 個固定のフェンスではノートが途中で閉じて以降が壊れる。
        code = "// ```\nint main() {}"
        fence = code_fence(code)
        self.assertEqual(fence, "````")
        self.assertNotIn(fence, code)


class RenderNoteTest(unittest.TestCase):
    def test_frontmatterに構造化データを置く(self):
        rendered = note()
        self.assertTrue(rendered.startswith("---\n"))
        for line in (
            'problem_id: "abc305_c"',
            'contest: "abc305"',
            "diff: 638",
            'lang: "C++"',
            "length: 1270",
            "exec_time: 12",
            'url: "https://atcoder.jp/contests/abc305/tasks/abc305_c"',
        ):
            self.assertIn(line, rendered)

    def test_問題ページは出題元コンテストで組む(self):
        # ADT で解き直した提出でも、問題ページは本来の abc305 を指すべき。
        rendered = note(submitted=submission(contest_id="adt_medium_20241127_1"))
        self.assertIn("[問題ページ](https://atcoder.jp/contests/abc305/tasks/abc305_c)", rendered)
        self.assertIn('contest: "abc305"', rendered)

    def test_提出ページは提出時のコンテストで組む(self):
        # 提出は ADT 配下にしか存在しないので、こちらは寄せ直してはいけない。
        rendered = note(submitted=submission(contest_id="adt_medium_20241127_1"))
        self.assertIn(
            "https://atcoder.jp/contests/adt_medium_20241127_1/submissions/42146394", rendered
        )

    def test_日付はJSTで解釈する(self):
        # epoch 1686401043 は JST で 2023-06-10 21:44。UTC 解釈だと 6/10 12:44 で、
        # 深夜の提出だと日付が 1 日ずれる。
        self.assertIn("date: 2023-06-10", note())
        # 2023-06-10 00:00 JST = 6/9 15:00 UTC。UTC で解釈すると前日になる。
        self.assertIn("date: 2023-06-10", note(submitted=submission(epoch=1686322800)))

    def test_確定タグと候補タグを別フィールドに持つ(self):
        rendered = note(
            tags=["典型/グラフ/ダイクストラ"],
            auto=["典型/データ構造/priority_queue"],
            tag_source="claude",
        )
        self.assertIn('tags: ["典型/グラフ/ダイクストラ"]', rendered)
        self.assertIn('auto_tags: ["典型/データ構造/priority_queue"]', rendered)
        self.assertIn('tag_source: "claude"', rendered)

    def test_コードを言語付きフェンスで埋め込む(self):
        self.assertIn("```cpp\nint main() {}\n```", note())

    def test_未知の拡張子は言語指定なしで埋め込む(self):
        self.assertIn("```\nint main() {}\n```", note(extension=".unknown"))

    def test_改行で終わらないコードでもフェンスが行頭に来る(self):
        self.assertIn("int main() {}\n```", note(code="int main() {}"))

    def test_何度生成しても同じ結果(self):
        self.assertEqual(note(), note())


class PruneStaleNotesTest(unittest.TestCase):
    """unlink する破壊的関数なので、消してよいものだけが消えることを固定する。"""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.dir = Path(self.tmp.name)
        self.addCleanup(self.tmp.cleanup)

    def _touch(self, name: str) -> Path:
        path = self.dir / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("x", encoding="utf-8")
        return path

    def test_今回書き出さなかったノートだけ消す(self):
        kept = self._touch("abc305_c.md")
        stale = self._touch("abc999_z.md")

        removed = prune_stale_notes(self.dir, {kept})

        self.assertEqual(removed, [stale])
        self.assertFalse(stale.exists())
        self.assertTrue(kept.exists())

    def test_md以外とサブディレクトリには触れない(self):
        obsidian = self._touch(".obsidian/app.json")
        other = self._touch("memo.txt")

        self.assertEqual(prune_stale_notes(self.dir, set()), [])
        self.assertTrue(obsidian.exists())
        self.assertTrue(other.exists())

    def test_書きかけの一時ファイルも掃除する(self):
        # write_atomic が中断されると .md.part が残る。放っておくと永久に残る。
        part = self._touch("abc305_c.md.part")
        self.assertEqual(prune_stale_notes(self.dir, set()), [part])


class PruneBlockerTest(unittest.TestCase):
    """全件を走り切っていないのに prune すると Vault が全消しになる。この境界を固定する。"""

    def test_全件を走り切ったときだけ消す(self):
        self.assertIsNone(prune_blocker(limit=None, written=1716, missing_code=0))

    def test_limit付きでは消さない(self):
        # --limit 5 は 5 問しか書かないので、残り 1,711 枚が「対象外」に見えてしまう。
        self.assertIsNotNone(prune_blocker(limit=5, written=5, missing_code=0))

    def test_limit0でも消さない(self):
        self.assertIsNotNone(prune_blocker(limit=0, written=0, missing_code=0))

    def test_書き出しが0件なら消さない(self):
        # submissions.json が空・壊れている・別ユーザーのもの、という事故で全消しになる。
        self.assertIsNotNone(prune_blocker(limit=None, written=0, missing_code=0))

    def test_コード未取得の問題があれば消さない(self):
        # fetch_code.py が途中までしか走っていないだけで、対象外になったわけではない。
        self.assertIsNotNone(prune_blocker(limit=None, written=10, missing_code=1))


class ValidateConfirmedTagsTest(unittest.TestCase):
    """M3 が作る外部ファイル。形が違えば Dataview の集計が静かに壊れるので落とす。"""

    def test_正しい形はそのまま通す(self):
        tags = {"abc305_c": ["典型/探索/幅優先探索"], "abc300_a": []}
        self.assertEqual(validate_confirmed_tags(tags), tags)

    def test_タグがリストでなければ落とす(self):
        with self.assertRaises(SystemExit):
            validate_confirmed_tags({"abc305_c": "典型/DP"})

    def test_タグに文字列以外が混ざれば落とす(self):
        with self.assertRaises(SystemExit):
            validate_confirmed_tags({"abc305_c": ["典型/DP", 42]})

    def test_最上位がオブジェクトでなければ落とす(self):
        with self.assertRaises(SystemExit):
            validate_confirmed_tags(["abc305_c"])


if __name__ == "__main__":
    unittest.main()
