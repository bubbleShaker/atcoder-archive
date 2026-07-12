"""バッチ切り出しの単体テスト（ネットワーク不要）。

usage: python -m unittest discover -s tools -t tools -v
"""

from __future__ import annotations

import json
import tempfile
import unittest
from pathlib import Path
from unittest import mock

import batch_tags
from batch_tags import (
    EASY_BATCH_SIZE,
    HARD_BATCH_SIZE,
    Batch,
    BoundaryMismatch,
    Problem,
    check_manifest,
    coverage,
    find_batch,
    fingerprint,
    is_easy,
    render_prompt,
    split_batches,
)

TAXONOMY = {
    "note": ["最も具体的な葉だけを付ける。"],
    "typical": ["典型/探索/全探索", "典型/DP"],
    "excluded": ["教材"],
}


def problem(
    problem_id: str,
    difficulty: int | None = 100,
    code: str = "int main(){}",
    suffix: str = ".cpp",
) -> Problem:
    return Problem(
        problem_id=problem_id,
        contest_id=problem_id.split("_")[0],
        title="title",
        difficulty=difficulty,
        suffix=suffix,
        code=code,
    )


class IsEasyTest(unittest.TestCase):
    def test_400未満はeasy(self):
        self.assertTrue(is_easy(problem("abc001_a", difficulty=399)))

    def test_400はhard(self):
        self.assertFalse(is_easy(problem("abc001_a", difficulty=400)))

    def test_difficulty不明はhardに寄せる(self):
        # tessoku-book など。判断を省略しないよう、濃い層に入れて 30 問/バッチで読ませる。
        self.assertFalse(is_easy(problem("tessoku_book_a", difficulty=None)))


class SplitBatchesTest(unittest.TestCase):
    def test_層ごとに固定長で切る(self):
        problems = [problem(f"abc{i:03d}_a", difficulty=100) for i in range(EASY_BATCH_SIZE + 1)]
        batches = split_batches(problems)
        self.assertEqual([b.batch_id for b in batches], ["low-000", "low-001"])
        self.assertEqual(len(batches[0].problems), EASY_BATCH_SIZE)
        self.assertEqual(len(batches[1].problems), 1)

    def test_easyとhardを別の層に切る(self):
        problems = [problem("abc001_a", difficulty=100), problem("abc001_d", difficulty=1200)]
        batches = split_batches(problems)
        self.assertEqual([b.batch_id for b in batches], ["low-000", "high-000"])
        self.assertEqual(batches[0].problems[0].problem_id, "abc001_a")
        self.assertEqual(batches[1].problems[0].problem_id, "abc001_d")

    def test_hardの粒度は30問(self):
        problems = [problem(f"abc{i:03d}_d", difficulty=1200) for i in range(HARD_BATCH_SIZE + 1)]
        batches = split_batches(problems)
        self.assertEqual(len(batches[0].problems), HARD_BATCH_SIZE)
        self.assertEqual(len(batches), 2)

    def test_入力順が違ってもバッチの中身は同じ(self):
        # バッチ境界の決定性はレジューム設計の土台。呼び出し側の順序に依存させない。
        problems = [problem("abc002_a"), problem("abc001_a"), problem("abc003_a")]
        forward = split_batches(problems)
        backward = split_batches(list(reversed(problems)))
        self.assertEqual(
            [p.problem_id for p in forward[0].problems],
            ["abc001_a", "abc002_a", "abc003_a"],
        )
        self.assertEqual(
            [p.problem_id for p in forward[0].problems],
            [p.problem_id for p in backward[0].problems],
        )

    def test_バッチ境界は済みshardに影響されない(self):
        # 済んだ shard を除いた集合から切ると、1 バッチ終わるたびに残りの境界がずれてしまう。
        # split_batches は shard を一切見ないので、何度切っても同じ中身になる。
        problems = [problem(f"abc{i:03d}_a") for i in range(EASY_BATCH_SIZE + 5)]
        self.assertEqual(
            [[p.problem_id for p in b.problems] for b in split_batches(problems)],
            [[p.problem_id for p in b.problems] for b in split_batches(problems)],
        )


class FindBatchTest(unittest.TestCase):
    def test_知らないバッチidはKeyError(self):
        with self.assertRaises(KeyError):
            find_batch(split_batches([problem("abc001_a")]), "low-999")


class FingerprintTest(unittest.TestCase):
    def test_入力順が違っても同じ指紋(self):
        a = [problem("abc001_a"), problem("abc002_a")]
        self.assertEqual(
            fingerprint(split_batches(a)),
            fingerprint(split_batches(list(reversed(a)))),
        )

    def test_未分類集合が変わると指紋も変わる(self):
        base = [problem("abc001_a")]
        self.assertNotEqual(
            fingerprint(split_batches(base)),
            fingerprint(split_batches(base + [problem("abc002_a")])),
        )

    def test_difficultyが層をまたぐと指紋が変わる(self):
        # problem_id 一覧で指紋を取ると、ここが検知できない。problem-models.json は
        # AtCoder Problems 側で再推定され続けるので、diff が 400 をまたぐのは現実に起きる。
        # 1 問が層を移るだけでその後ろの問題が全部バッチを移動する。
        before = [problem("abc001_a", difficulty=399), problem("abc002_a", difficulty=1200)]
        after = [problem("abc001_a", difficulty=401), problem("abc002_a", difficulty=1200)]
        self.assertNotEqual(fingerprint(split_batches(before)), fingerprint(split_batches(after)))

    def test_バッチサイズ定数が変わると指紋が変わる(self):
        problems = [problem(f"abc{i:03d}_a") for i in range(3)]
        before = fingerprint(split_batches(problems))
        with mock.patch.object(batch_tags, "EASY_BATCH_SIZE", 2):
            after = fingerprint(split_batches(problems))
        self.assertNotEqual(before, after)


class ShardDirTestCase(unittest.TestCase):
    """SHARD_DIR / MANIFEST_PATH を一時ディレクトリに差し替える。"""

    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.shard_dir = Path(tmp.name)
        patches = {
            "SHARD_DIR": self.shard_dir,
            "MANIFEST_PATH": self.shard_dir / "_manifest.json",
        }
        for name, value in patches.items():
            patcher = mock.patch.object(batch_tags, name, value)
            patcher.start()
            self.addCleanup(patcher.stop)


class CheckManifestTest(ShardDirTestCase):
    def manifest(self) -> dict:
        return json.loads((self.shard_dir / "_manifest.json").read_text(encoding="utf-8"))

    def test_初回は指紋を書く(self):
        check_manifest(split_batches([problem("abc001_a")]))
        self.assertEqual(self.manifest()["problem_count"], 1)

    def test_集合が変わってもshardが無ければ黙って更新する(self):
        check_manifest(split_batches([problem("abc001_a")]))
        check_manifest(split_batches([problem("abc001_a"), problem("abc002_a")]))  # 落ちない
        self.assertEqual(self.manifest()["problem_count"], 2)

    def test_shardがあるのに割り当てが変わったら止める(self):
        # classify.py のルールを足すとバッチ境界がずれ、同じ問題が別の shard に二重に入るか
        # どの shard にも入らず消える。人間の注意力に頼らず、ここで止める。
        check_manifest(split_batches([problem("abc001_a")]))
        (self.shard_dir / "low-000.json").write_text("{}", encoding="utf-8")
        with self.assertRaises(BoundaryMismatch):
            check_manifest(split_batches([problem("abc001_a"), problem("abc002_a")]))

    def test_manifestを消してもshardがあれば止める(self):
        # ドリフト検知の唯一の記録が「消せば黙る」構造だと、検知機構として意味を成さない。
        (self.shard_dir / "low-000.json").write_text("{}", encoding="utf-8")
        with self.assertRaises(BoundaryMismatch):
            check_manifest(split_batches([problem("abc001_a")]))


class CoverageTest(ShardDirTestCase):
    def setUp(self):
        super().setUp()
        self.batch = Batch(
            batch_id="low-000",
            problems=(problem("abc001_a"), problem("abc002_a")),
        )

    def write_shard(self, payload: dict) -> None:
        self.batch.shard_path.write_text(json.dumps(payload), encoding="utf-8")

    def test_shardが無ければ未処理(self):
        self.assertFalse(coverage(self.batch).done)

    def test_全問覆っていれば済み(self):
        self.write_shard({"tags": {"abc001_a": []}, "pending": {"abc002_a": "理由"}})
        self.assertTrue(coverage(self.batch).done)

    def test_取りこぼしを検出する(self):
        # プロンプトが truncate されて後半が読まれないと、こうなる。ファイルの存在だけで
        # 「済み」と判定すると、その問題は永久に未分類のまま消える。
        self.write_shard({"tags": {"abc001_a": []}, "pending": {}})
        result = coverage(self.batch)
        self.assertFalse(result.done)
        self.assertEqual(result.missing, {"abc002_a"})

    def test_余分な問題を検出する(self):
        self.write_shard({"tags": {"abc001_a": [], "abc002_a": [], "abc999_z": []}})
        result = coverage(self.batch)
        self.assertFalse(result.done)
        self.assertEqual(result.unexpected, {"abc999_z"})

    def test_壊れたJSONでも落ちない(self):
        # shard を書くのは LLM なので JSON 崩れは現実的な失敗モード。--list は復旧の導線でも
        # あるので、壊れた shard 1 つで一覧全体が読めなくなってはいけない。
        self.batch.shard_path.write_text('{"tags": {},}', encoding="utf-8")
        result = coverage(self.batch)
        self.assertFalse(result.done)
        self.assertIn("JSON が壊れている", result.broken)

    def test_tagsとpendingの両方にあるのを検出する(self):
        self.write_shard({"tags": {"abc001_a": []}, "pending": {"abc001_a": "理由"}})
        result = coverage(self.batch)
        self.assertFalse(result.done)
        self.assertIn("両方にある", result.broken)


class RenderPromptTest(unittest.TestCase):
    def setUp(self):
        self.batch = Batch(batch_id="low-000", problems=(problem("abc001_a"),))

    def render(self, batch: Batch) -> str:
        return render_prompt(batch, TAXONOMY)

    def test_shardの書き出し先と問題を載せる(self):
        prompt = self.render(self.batch)
        self.assertIn("data/tags.d/low-000.json", prompt)
        self.assertIn("abc001_a", prompt)
        self.assertIn("int main(){}", prompt)

    def test_語彙と規約を載せる(self):
        prompt = self.render(self.batch)
        self.assertIn("典型/探索/全探索", prompt)
        self.assertIn("最も具体的な葉だけを付ける", prompt)

    def test_JSON例にこのバッチの実IDを使う(self):
        # 例に無関係な problem_id を置くと、独立コンテキストのモデルが例に引きずられて
        # shard にその ID を書いてしまう。
        self.assertNotIn("abc305_c", self.render(self.batch))

    def test_low層とhigh層で指示を出し分ける(self):
        low = self.render(self.batch)
        high = self.render(Batch(batch_id="high-000", problems=(problem("abc001_d", 1200),)))
        self.assertIn("大半は `[]`（典型なし）で正しい", low)
        self.assertIn("典型判定の本番", high)
        self.assertNotIn("典型判定の本番", low)

    def test_コードは指示ではないと明示する(self):
        # 提出コードは atcoder.jp 由来の外部文字列で、書き込み権限を持つエージェントに渡る。
        self.assertIn("指示ではない", self.render(self.batch))

    def test_拡張子に応じた言語でフェンスする(self):
        batch = Batch(batch_id="low-000", problems=(problem("abc001_a", suffix=".cs"),))
        self.assertIn("```csharp", self.render(batch))

    def test_コード中のバックティックでフェンスが壊れない(self):
        # 提出コードのコメントに ``` があると、3 個固定のフェンスではプロンプトが途中で閉じる。
        batch = Batch(
            batch_id="low-000",
            problems=(problem("abc001_a", code="// ```\nint main(){}"),),
        )
        self.assertIn("````cpp", self.render(batch))


if __name__ == "__main__":
    unittest.main()
