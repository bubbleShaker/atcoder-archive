"""shard の検証と集約の単体テスト（ネットワーク不要）。

usage: python -m unittest discover -s tools -t tools -v

語彙は実物（data/taxonomy.json）を使う。ここで語彙をモックすると、merge が本番で弾くべき
タグを弾けているかを確かめたことにならない（この検証こそが merge_tags の存在理由）。
"""

from __future__ import annotations

import io
import json
import unittest
from pathlib import Path
from unittest import mock

import merge_tags
from batch_tags import Batch
from merge_tags import (
    Merged,
    ParsedShard,
    ShardError,
    load_shards,
    merge_shards,
    parse_shard,
    print_stats,
    render_tags_json,
    run,
    shrink_reason,
)
from test_batch_tags import ShardDirTestCase, problem


class ParseShardTest(unittest.TestCase):
    def parse(self, payload: dict, batch_id: str = "low-000") -> ParsedShard:
        return parse_shard(payload, batch_id)

    def test_タグと保留を読む(self):
        shard = self.parse(
            {
                "batch": "low-000",
                "tags": {"abc001_a": ["典型/探索/全探索"], "abc002_a": []},
                "pending": {"abc003_a": "入出力だけで何をしているか読めない"},
            }
        )
        self.assertEqual(shard.tags, {"abc001_a": ["典型/探索/全探索"], "abc002_a": []})
        self.assertEqual(shard.pending["abc003_a"], "入出力だけで何をしているか読めない")

    def test_空リストは典型なしの確定として残す(self):
        # キーが無いのは「未処理」。意味が違うので、空リストを落としてはいけない。
        shard = self.parse({"tags": {"abc001_a": []}})
        self.assertIn("abc001_a", shard.tags)

    def test_語彙外のタグを弾く(self):
        # 独立コンテキストのサブエージェントが `典型/探索/全列挙` を勝手に作る事故を止める。
        with self.assertRaises(ShardError) as caught:
            self.parse({"tags": {"abc001_a": ["典型/探索/全列挙"]}})
        self.assertIn("語彙に無いタグ", str(caught.exception))

    def test_除外タグをClaudeが書いたら弾く(self):
        # 教材・ヒューリスティックは contest_id から機械的に決まる。Claude が判断してはいけない。
        with self.assertRaises(ShardError) as caught:
            self.parse({"tags": {"apg4b_a": ["教材"]}})
        self.assertIn("語彙に無いタグ", str(caught.exception))

    def test_冗長な親タグは葉だけに正規化する(self):
        # Obsidian も Dataview も前置一致で展開するので意味は等価。100 問のバッチを
        # 書式ゆれだけで再実行させる価値は無い。
        shard = self.parse({"tags": {"abc001_a": ["典型/DP", "典型/DP/桁DP"]}})
        self.assertEqual(shard.tags["abc001_a"], ["典型/DP/桁DP"])
        self.assertEqual(shard.normalized, ("abc001_a",))

    def test_子タグの無い親タグはそのまま残す(self):
        # 裸の親は「そのカテゴリだが下位分類のどれでもない」枠。正規化の対象ではない。
        shard = self.parse({"tags": {"abc001_a": ["典型/DP"]}})
        self.assertEqual(shard.tags["abc001_a"], ["典型/DP"])
        self.assertEqual(shard.normalized, ())

    def test_タグの重複は畳む(self):
        shard = self.parse({"tags": {"abc001_a": ["典型/DP", "典型/DP"]}})
        self.assertEqual(shard.tags["abc001_a"], ["典型/DP"])

    def test_タグが文字列のリストでなければ弾く(self):
        with self.assertRaises(ShardError):
            self.parse({"tags": {"abc001_a": "典型/DP"}})

    def test_エラーは全部集めてから投げる(self):
        # 100 問のバッチで語彙外が 5 個あるとき、直す→走らせるを 5 往復させない。
        with self.assertRaises(ShardError) as caught:
            self.parse({"tags": {"abc001_a": ["未知1"], "abc002_a": ["未知2"]}})
        message = str(caught.exception)
        self.assertIn("abc001_a", message)
        self.assertIn("abc002_a", message)

    def test_書き出し先を取り違えたshardを弾く(self):
        # 別バッチのプロンプトを読んでこのファイルに書いた場合。中身は妥当に見えるのに
        # 問題が丸ごと入れ替わっている。
        with self.assertRaises(ShardError) as caught:
            self.parse({"batch": "high-003", "tags": {}}, batch_id="low-000")
        self.assertIn("書き出し先の取り違え", str(caught.exception))

    def test_理由の無い保留を弾く(self):
        # 理由が無いと M3-4（問題文スクレイプの要否判断）の材料にならない。
        with self.assertRaises(ShardError) as caught:
            self.parse({"tags": {}, "pending": {"abc001_a": "  "}})
        self.assertIn("理由が空", str(caught.exception))

    def test_tagsとpendingの両方にあるのを弾く(self):
        with self.assertRaises(ShardError) as caught:
            self.parse({"tags": {"abc001_a": []}, "pending": {"abc001_a": "理由"}})
        self.assertIn("両方にある", str(caught.exception))

    def test_最上位が壊れていれば弾く(self):
        with self.assertRaises(ShardError):
            parse_shard([], "low-000")
        with self.assertRaises(ShardError):
            parse_shard({"tags": []}, "low-000")


class MergeShardsTest(unittest.TestCase):
    def shard(self, batch_id: str, tags: dict, pending: dict | None = None) -> ParsedShard:
        return ParsedShard(batch_id=batch_id, tags=tags, pending=pending or {})

    def test_shardをまたいで集約する(self):
        merged = merge_shards(
            [
                self.shard("low-001", {"abc002_a": []}),
                self.shard("low-000", {"abc001_a": ["典型/DP"]}),
            ]
        )
        self.assertEqual(merged.tags, {"abc001_a": ["典型/DP"], "abc002_a": []})

    def test_キー順を固定する(self):
        # 挿入順のままだと shard を 1 つやり直すたびに tags.json 全体が並び替わり diff が読めない。
        merged = merge_shards([self.shard("low-000", {"abc009_a": [], "abc001_a": []})])
        self.assertEqual(list(merged.tags), ["abc001_a", "abc009_a"])

    def test_problem_idの衝突を弾く(self):
        # バッチ境界がずれたまま走らせた印。片方を黙って採ると、どちらの判定が生き残ったのか
        # 後から追えない。
        with self.assertRaises(ShardError) as caught:
            merge_shards(
                [
                    self.shard("low-000", {"abc001_a": ["典型/DP"]}),
                    self.shard("low-001", {"abc001_a": []}),
                ]
            )
        self.assertIn("abc001_a", str(caught.exception))

    def test_tagsとpendingをまたいだ衝突も弾く(self):
        with self.assertRaises(ShardError):
            merge_shards(
                [
                    self.shard("low-000", {"abc001_a": []}),
                    self.shard("low-001", {}, {"abc001_a": "理由"}),
                ]
            )

    def test_保留は出所のバッチと共に残す(self):
        merged = merge_shards([self.shard("high-000", {}, {"abc001_d": "問題文が要る"})])
        self.assertEqual(merged.pending["abc001_d"], ("high-000", "問題文が要る"))


class RenderTagsJsonTest(unittest.TestCase):
    def test_日本語をエスケープせず末尾に改行を付ける(self):
        rendered = render_tags_json({"abc001_a": ["典型/DP"]})
        self.assertIn("典型/DP", rendered)
        self.assertTrue(rendered.endswith("\n"))
        self.assertEqual(json.loads(rendered), {"abc001_a": ["典型/DP"]})

    def test_build_vaultの検証を通る形で書く(self):
        # tags.json の唯一の読み手。ここが割れると Vault の frontmatter が静かに壊れる。
        from build_vault import validate_confirmed_tags

        rendered = render_tags_json(merge_shards([]).tags | {"abc001_a": []})
        self.assertEqual(validate_confirmed_tags(json.loads(rendered)), {"abc001_a": []})


class ShardFileTestCase(ShardDirTestCase):
    """SHARD_DIR に加えて TAGS_PATH も一時ディレクトリに逃がす。"""

    def setUp(self):
        super().setUp()
        self.batch = Batch(batch_id="low-000", problems=(problem("abc001_a"), problem("abc002_a")))
        self.tags_path = self.shard_dir / "tags.json"
        patcher = mock.patch.object(merge_tags, "TAGS_PATH", self.tags_path)
        patcher.start()
        self.addCleanup(patcher.stop)

    def write_shard(self, payload: object, path: Path | None = None) -> None:
        text = payload if isinstance(payload, str) else json.dumps(payload, ensure_ascii=False)
        (path or self.batch.shard_path).write_text(text, encoding="utf-8")


class LoadShardsTest(ShardFileTestCase):
    def test_shardが無ければ未処理として返す(self):
        loaded = load_shards([self.batch])
        self.assertEqual((loaded.shards, loaded.blocked, loaded.untouched), ([], [], ["low-000"]))

    def test_全問覆っていれば読む(self):
        self.write_shard({"tags": {"abc001_a": ["典型/DP"], "abc002_a": []}})
        loaded = load_shards([self.batch])
        self.assertEqual(loaded.blocked, [])
        self.assertEqual(loaded.shards[0].tags["abc001_a"], ["典型/DP"])

    def test_取りこぼしのあるshardは通さない(self):
        # プロンプトが truncate されて後半が読まれなかった場合。混ぜて通すと、その問題は
        # 「未分類でもない・確定でもない」状態で永久に消える。
        self.write_shard({"tags": {"abc001_a": []}})
        loaded = load_shards([self.batch])
        self.assertEqual(loaded.shards, [])
        self.assertIn("未記載 1 問", loaded.blocked[0])

    def test_他バッチの問題が混ざったshardは通さない(self):
        self.write_shard({"tags": {"abc001_a": [], "abc002_a": [], "abc999_z": []}})
        loaded = load_shards([self.batch])
        self.assertEqual(loaded.shards, [])
        self.assertIn("abc999_z", loaded.blocked[0])

    def test_壊れたJSONは通さない(self):
        self.write_shard('{"tags": {},}')
        self.assertIn("JSON が壊れている", load_shards([self.batch]).blocked[0])

    def test_語彙外タグのshardは通さない(self):
        self.write_shard({"tags": {"abc001_a": ["典型/知らないタグ"], "abc002_a": []}})
        loaded = load_shards([self.batch])
        self.assertEqual(loaded.shards, [])
        self.assertIn("語彙に無いタグ", loaded.blocked[0])

    def test_バッチに対応しないshardを名指しする(self):
        # `low-01.json` のようなゼロ埋め違い。どのバッチからも参照されず中身が捨てられる。
        self.write_shard({"tags": {}}, path=self.shard_dir / "low-01.json")
        self.assertEqual(load_shards([self.batch]).strays, ["low-01.json"])


class ShrinkReasonTest(ShardFileTestCase):
    def test_tags_jsonが無ければ止めない(self):
        self.assertIsNone(shrink_reason(0, self.tags_path))

    def test_増えるなら止めない(self):
        self.tags_path.write_text(json.dumps({"abc001_a": []}), encoding="utf-8")
        self.assertIsNone(shrink_reason(2, self.tags_path))

    def test_減るなら止める(self):
        # 復旧手順（tags.d を捨てて切り直す）がそのまま「確定タグ全消し」になる導線を塞ぐ。
        self.tags_path.write_text(json.dumps({"abc001_a": [], "abc002_a": []}), encoding="utf-8")
        self.assertIn("確定タグが減る", shrink_reason(0, self.tags_path) or "")


class RunTest(ShardFileTestCase):
    def run_merge(self, **kwargs) -> str:
        out = io.StringIO()
        run([self.batch], out=out, **kwargs)
        return out.getvalue()

    def test_通ったshardをtags_jsonに書く(self):
        self.write_shard({"tags": {"abc001_a": ["典型/DP"], "abc002_a": []}})
        self.run_merge()
        self.assertEqual(
            json.loads(self.tags_path.read_text(encoding="utf-8")),
            {"abc001_a": ["典型/DP"], "abc002_a": []},
        )

    def test_信用できないshardがあれば一切書かない(self):
        # merge_tags の存在理由そのもの。1 つでも怪しければ tags.json に到達させない。
        self.write_shard({"tags": {"abc001_a": ["未知のタグ"], "abc002_a": []}})
        with self.assertRaises(SystemExit):
            self.run_merge()
        self.assertFalse(self.tags_path.exists())

    def test_保留はtags_jsonに混ぜない(self):
        # 保留を `[]` として書くと「典型なし確定」になり、Vault に静かな誤りが載る。
        self.write_shard({"tags": {"abc001_a": []}, "pending": {"abc002_a": "問題文が要る"}})
        self.run_merge()
        self.assertEqual(list(json.loads(self.tags_path.read_text(encoding="utf-8"))), ["abc001_a"])

    def test_確定タグが減る上書きを止める(self):
        self.tags_path.write_text(
            json.dumps({"abc001_a": [], "abc002_a": [], "abc003_a": []}), encoding="utf-8"
        )
        self.write_shard({"tags": {"abc001_a": [], "abc002_a": []}})
        with self.assertRaises(SystemExit) as caught:
            self.run_merge()
        self.assertIn("確定タグが減る", str(caught.exception))
        self.assertEqual(len(json.loads(self.tags_path.read_text(encoding="utf-8"))), 3)

    def test_forceなら減る上書きを許す(self):
        self.tags_path.write_text(
            json.dumps({"abc001_a": [], "abc002_a": [], "abc003_a": []}), encoding="utf-8"
        )
        self.write_shard({"tags": {"abc001_a": [], "abc002_a": []}})
        self.run_merge(force=True)
        self.assertEqual(len(json.loads(self.tags_path.read_text(encoding="utf-8"))), 2)

    def test_dry_runは書かない(self):
        self.write_shard({"tags": {"abc001_a": [], "abc002_a": []}})
        output = self.run_merge(dry_run=True)
        self.assertFalse(self.tags_path.exists())
        self.assertIn("書いていない", output)


class PrintStatsTest(unittest.TestCase):
    def test_典型ありなしと保留の理由を出す(self):
        out = io.StringIO()
        print_stats(
            Merged(
                tags={"abc001_a": ["典型/DP"], "abc002_a": []},
                pending={"abc003_d": ("high-000", "問題文が要る")},
            ),
            out=out,
        )
        text = out.getvalue()
        self.assertIn("確定 2 問（典型あり 1 / 典型なし 1）", text)
        self.assertIn("典型/DP", text)
        self.assertIn("保留 1 問", text)
        self.assertIn("問題文が要る", text)


if __name__ == "__main__":
    unittest.main()
