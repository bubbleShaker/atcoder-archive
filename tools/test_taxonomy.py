"""タグ語彙の単体テスト（ネットワーク不要）。

usage: python -m unittest discover -s tools -t tools -v
"""

from __future__ import annotations

import tempfile
import unittest
from pathlib import Path

import classify
from taxonomy import (
    TaxonomyError,
    allowed_tags,
    confirmable_tags,
    load_taxonomy,
    parse_taxonomy,
    unknown_tags,
)


def taxonomy_data(**overrides: object) -> dict:
    base: dict = {"version": 1, "typical": ["典型/DP"], "excluded": ["教材"]}
    base.update(overrides)
    return base


class ParseTaxonomyTest(unittest.TestCase):
    def test_正しい語彙を読める(self):
        parsed = parse_taxonomy(taxonomy_data())
        self.assertEqual(parsed, {"typical": ["典型/DP"], "excluded": ["教材"]})

    def test_未知のversionを弾く(self):
        with self.assertRaises(TaxonomyError):
            parse_taxonomy(taxonomy_data(version=2))

    def test_重複タグを弾く(self):
        with self.assertRaises(TaxonomyError):
            parse_taxonomy(taxonomy_data(typical=["典型/DP", "典型/DP"]))

    def test_typicalとexcludedの重なりを弾く(self):
        with self.assertRaises(TaxonomyError):
            parse_taxonomy(taxonomy_data(typical=["典型/DP"], excluded=["典型/DP"]))

    def test_空のセグメントを含むタグを弾く(self):
        # 空文字や `典型//DP` は build_vault の型検証を素通りして frontmatter に出てしまう。
        for broken in ("", "典型//DP", "典型/DP/"):
            with self.subTest(tag=broken):
                with self.assertRaises(TaxonomyError):
                    parse_taxonomy(taxonomy_data(typical=[broken]))

    def test_典型プレフィクスの無いtypicalを弾く(self):
        with self.assertRaises(TaxonomyError):
            parse_taxonomy(taxonomy_data(typical=["貪欲"]))

    def test_深すぎるタグを弾く(self):
        with self.assertRaises(TaxonomyError):
            parse_taxonomy(taxonomy_data(typical=["典型/DP/桁DP/さらに"]))

    def test_リストでないtypicalを弾く(self):
        with self.assertRaises(TaxonomyError):
            parse_taxonomy(taxonomy_data(typical="典型/DP"))


class LoadTaxonomyTest(unittest.TestCase):
    def test_実ファイルを読める(self):
        taxonomy = load_taxonomy()
        self.assertIn("典型/探索/全探索", taxonomy["typical"])
        self.assertIn("教材", taxonomy["excluded"])

    def test_壊れたJSONをTaxonomyErrorに畳む(self):
        # 手編集を前提にしている以上、末尾カンマのような構文エラーは想定内の事象。
        # JSONDecodeError のまま漏らすと merge_tags の except TaxonomyError を素通りする。
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "taxonomy.json"
            path.write_text('{"version": 1,}', encoding="utf-8")
            with self.assertRaises(TaxonomyError):
                load_taxonomy(path)

    def test_ファイルが無ければTaxonomyError(self):
        with tempfile.TemporaryDirectory() as tmp:
            with self.assertRaises(TaxonomyError):
                load_taxonomy(Path(tmp) / "no-such-taxonomy.json")


class HierarchyTest(unittest.TestCase):
    def test_カテゴリはPLAN_mdで決めた8つ(self):
        # タグは `典型/カテゴリ[/小分類]`。第 1 セグメントは常に `典型`。
        categories = {tag.split("/")[1] for tag in load_taxonomy()["typical"]}
        self.assertEqual(
            categories,
            {"探索", "DP", "グラフ", "数学", "データ構造", "文字列", "貪欲", "実装"},
        )

    def test_全カテゴリに裸の親タグがある(self):
        # 「そのカテゴリだが下位分類のどれでもない」を表現できないと、バッチが語彙外タグを
        # でっち上げるか、無理やり近い小分類に寄せるかに割れる。
        typical = load_taxonomy()["typical"]
        categories = {tag.split("/")[1] for tag in typical}
        parents = {tag for tag in typical if tag.count("/") == 1}
        self.assertEqual(parents, {f"典型/{c}" for c in categories})


class UnknownTagsTest(unittest.TestCase):
    def test_典型タグなら空(self):
        self.assertEqual(unknown_tags(["典型/貪欲", "典型/DP/桁DP"]), [])

    def test_語彙外を返す(self):
        # `全列挙` は `全探索` の言い換え。こうした揺れを弾くための語彙である。
        self.assertEqual(unknown_tags(["典型/探索/全列挙"]), ["典型/探索/全列挙"])

    def test_確定タグに除外タグは使えない(self):
        # 教材・ヒューリスティックは contest_id から機械的に決まる。Claude が付けたら弾く。
        self.assertEqual(unknown_tags(["教材"]), ["教材"])
        self.assertEqual(unknown_tags(["ヒューリスティック"]), ["ヒューリスティック"])

    def test_静的解析の検査では除外タグを通す(self):
        self.assertEqual(unknown_tags(["教材"], confirmable_only=False), [])


class StaticRulesAreInTaxonomyTest(unittest.TestCase):
    """classify.py にルールを足して taxonomy.json への登録を忘れる、というズレを防ぐ。

    静的解析のタグは auto_tags としてノートに残り続けるので、語彙に無いと
    確定タグと突き合わせた監査ができなくなる。
    """

    def test_静的解析の全タグが語彙に載っている(self):
        self.assertEqual(classify.rule_tags() - allowed_tags(), frozenset())

    def test_除外タグはconfirmableに含まれない(self):
        self.assertEqual(confirmable_tags() & {classify.MATERIAL_TAG, classify.HEURISTIC_TAG}, set())


if __name__ == "__main__":
    unittest.main()
