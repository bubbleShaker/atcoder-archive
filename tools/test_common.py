"""パース処理・パス生成・ページングの単体テスト（ネットワーク不要）。

usage: python -m unittest discover -s tools -t tools -v
"""

from __future__ import annotations

import json
import unittest
from pathlib import Path

from common import (
    FetchError,
    UnsafeIdError,
    extract_submission_code,
    language_name,
    pick_latest_ac,
    problem_code_path,
    source_extension,
)
from fetch_meta import PAGE_SIZE, fetch_all_submissions


def submission(
    submission_id=1,
    problem_id="abc300_a",
    contest_id="abc300",
    epoch=100,
    result="AC",
    language="C++ 20 (gcc 12.2)",
):
    return {
        "id": submission_id,
        "problem_id": problem_id,
        "contest_id": contest_id,
        "epoch_second": epoch,
        "result": result,
        "language": language,
    }


class ExtractSubmissionCodeTest(unittest.TestCase):
    def test_シンタックスハイライトのタグを除去して本文を取り出す(self):
        page = (
            '<div><pre id="submission-code" class="prettyprint">'
            '<span class="com">// memo</span>\n'
            '<span class="kwd">int</span> main<span class="pun">()</span>'
            "</pre></div>"
        )
        self.assertEqual(extract_submission_code(page), "// memo\nint main()")

    def test_HTMLエスケープを元に戻す(self):
        page = '<pre id="submission-code">a &lt; b &amp;&amp; c &gt; d</pre>'
        self.assertEqual(extract_submission_code(page), "a < b && c > d")

    def test_コード欄が無ければ例外(self):
        with self.assertRaises(FetchError):
            extract_submission_code("<html><body>404</body></html>")


class PickLatestAcTest(unittest.TestCase):
    def test_同じ問題の複数ACから最新を選ぶ(self):
        latest = pick_latest_ac(
            [
                submission(1, epoch=100),
                submission(2, epoch=300),
                submission(3, epoch=200),
            ]
        )
        self.assertEqual(latest["abc300_a"]["id"], 2)

    def test_AC以外は対象外(self):
        self.assertEqual(
            pick_latest_ac([submission(1, result="WA"), submission(2, result="TLE")]),
            {},
        )

    def test_WAが最新でもACを拾う(self):
        latest = pick_latest_ac(
            [submission(1, epoch=100), submission(2, epoch=999, result="WA")]
        )
        self.assertEqual(latest["abc300_a"]["id"], 1)

    def test_同時刻のACはidが大きい方を採る(self):
        latest = pick_latest_ac([submission(7, epoch=100), submission(3, epoch=100)])
        self.assertEqual(latest["abc300_a"]["id"], 7)


class SourceExtensionTest(unittest.TestCase):
    def test_言語名からバージョンを落として正規化する(self):
        self.assertEqual(language_name("C++ 20 (gcc 12.2)"), "C++")
        self.assertEqual(language_name("C++23 (gcc 12.2)"), "C++")
        self.assertEqual(language_name("C# 11.0 (.NET 7.0.7)"), "C#")
        self.assertEqual(language_name("PyPy3 (7.3.0)"), "PyPy")

    def test_言語名から拡張子を決める(self):
        self.assertEqual(source_extension("C++ 20 (gcc 12.2)"), ".cpp")
        self.assertEqual(source_extension("C (GCC 9.2.1)"), ".c")
        self.assertEqual(source_extension("Python (CPython 3.11.4)"), ".py")
        self.assertEqual(source_extension("C# 11.0 (.NET 7.0.7)"), ".cs")

    def test_JavaScriptをJavaと取り違えない(self):
        # 前方一致で引くと "JavaScript".startswith("Java") が成立して .java になる。
        self.assertEqual(source_extension("JavaScript (Node.js 18.16.1)"), ".js")
        self.assertEqual(source_extension("Java (OpenJDK 17)"), ".java")

    def test_未知の言語はtxtに落とす(self):
        self.assertEqual(source_extension("Brainfuck (bf 20041219)"), ".txt")


class ProblemCodePathTest(unittest.TestCase):
    def setUp(self):
        self.code_dir = Path("/tmp/code")

    def test_コンテストごとのディレクトリに問題IDで保存する(self):
        path = problem_code_path(self.code_dir, submission())
        self.assertEqual(path, self.code_dir / "abc300" / "abc300_a.cpp")

    def test_ディレクトリを脱出するcontest_idを拒否する(self):
        with self.assertRaises(UnsafeIdError):
            problem_code_path(self.code_dir, submission(contest_id="../../etc"))

    def test_区切り文字を含むproblem_idを拒否する(self):
        for dangerous in ("a/b", "a\\b", "C:evil", "..", "a b"):
            with self.assertRaises(UnsafeIdError):
                problem_code_path(self.code_dir, submission(problem_id=dangerous))


class FetchAllSubmissionsTest(unittest.TestCase):
    def _fetcher(self, pages):
        """URL の from_second を見て、対応するページを返す偽の取得関数。"""
        calls = []

        def fetch(url: str) -> bytes:
            from_second = int(url.split("from_second=")[1])
            calls.append(from_second)
            if len(calls) > 10:
                raise AssertionError("ページングが止まっていない")
            return json.dumps(pages.get(from_second, [])).encode()

        return fetch, calls

    def test_500件未満なら1リクエストで終わる(self):
        fetch, calls = self._fetcher({0: [submission(1, epoch=10)]})
        result = fetch_all_submissions("Coji", fetch)
        self.assertEqual(len(result), 1)
        self.assertEqual(calls, [0])

    def test_ページを跨いで全件集める(self):
        first = [submission(i, epoch=i) for i in range(1, PAGE_SIZE + 1)]
        fetch, _ = self._fetcher({0: first, PAGE_SIZE: [submission(9999, epoch=9999)]})
        result = fetch_all_submissions("Coji", fetch)
        self.assertEqual(len(result), PAGE_SIZE + 1)

    def test_同一秒を跨ぐ提出を取りこぼさない(self):
        # 500 件目と 501 件目が同じ秒。次ページを epoch+1 から取ると 501 件目が消える。
        first = [submission(i, epoch=min(i, 500)) for i in range(1, PAGE_SIZE + 1)]
        second = [submission(500, epoch=500), submission(501, epoch=500)]
        fetch, _ = self._fetcher({0: first, 500: second})
        result = fetch_all_submissions("Coji", fetch)
        self.assertEqual(len(result), PAGE_SIZE + 1)
        self.assertIn(501, [s["id"] for s in result])

    def test_同じページが返り続けても無限ループしない(self):
        # 1 秒に 500 件以上あると from_second が前進しない。新規ゼロで打ち切る。
        same_second = [submission(i, epoch=42) for i in range(1, PAGE_SIZE + 1)]
        fetch, calls = self._fetcher({0: same_second, 42: same_second})
        result = fetch_all_submissions("Coji", fetch)
        self.assertEqual(len(result), PAGE_SIZE)
        self.assertLessEqual(len(calls), 3)

    def test_提出ゼロなら空を返す(self):
        fetch, _ = self._fetcher({})
        self.assertEqual(fetch_all_submissions("NoSuchUser", fetch), [])


if __name__ == "__main__":
    unittest.main()
