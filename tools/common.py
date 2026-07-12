"""取得スクリプト共通の HTTP ユーティリティとパーサ。

パース処理（extract_submission_code / pick_latest_ac / source_extension /
problem_code_path）はネットワークに依存しない純粋関数として切り出してある。
壊れたときに真っ先に疑うべき箇所であり、単体テストを当てられるようにするため。
"""

from __future__ import annotations

import gzip
import html as html_mod
import re
import time
import urllib.error
import urllib.parse
import urllib.request
from pathlib import Path

# AtCoder は素の User-Agent（python-urllib/*）に 403 を返すため、ブラウザ相当を名乗る必要がある。
# 一方 kenkoooo（AtCoder Problems）は API 利用者に識別可能な UA を求めているので、
# 偽装が不可欠な atcoder.jp にだけ Chrome を名乗り、それ以外では素性を明かす。
BROWSER_USER_AGENT = (
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
    "(KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
)
IDENTIFIED_USER_AGENT = (
    "atcoder-archive/1.0 (+https://github.com/bubbleShaker/atcoder-archive)"
)
_BROWSER_UA_HOSTS = {"atcoder.jp"}

# 相手サーバへの礼儀。負荷をかけると IP 制限を受けるので、急ぐ理由がない以上は安全側に振る。
# この間隔は http_get の内部で強制する。呼び出し側の sleep に頼ると、
# 新しいスクリプトが書き忘れた瞬間に無制限アクセスになるため。
REQUEST_INTERVAL_SEC = 1.0
_last_request_at = 0.0

DATA_DIR = Path(__file__).resolve().parent.parent / "data"

# contest_id / problem_id は kenkoooo API 由来（= 自分の制御下にない値）で、
# そのままファイルパスに使う。".." や ":" のような細工でデータディレクトリの外に
# 書き出されないよう、許可する文字を明示する。実データ 3,493 件は全てこれに収まる。
_SAFE_ID_RE = re.compile(r"\A[A-Za-z0-9_-]+\Z")


class FetchError(RuntimeError):
    """リトライしても回復しなかった取得失敗。"""


class UnsafeIdError(ValueError):
    """ファイルパスに使うには危険な contest_id / problem_id。"""


def _user_agent_for(url: str) -> str:
    host = urllib.parse.urlparse(url).hostname or ""
    return BROWSER_USER_AGENT if host in _BROWSER_UA_HOSTS else IDENTIFIED_USER_AGENT


def _throttle() -> None:
    global _last_request_at
    wait = REQUEST_INTERVAL_SEC - (time.monotonic() - _last_request_at)
    if wait > 0:
        time.sleep(wait)
    _last_request_at = time.monotonic()


def http_get(url: str, *, retries: int = 3) -> bytes:
    """レート制限を守って GET する。gzip 応答は透過的に展開する。

    429/5xx は指数バックオフでリトライする（一時的な混雑と恒久的な失敗を区別するため）。
    429 が Retry-After を返してきた場合はその指示に従う。
    """
    last_error: Exception | None = None
    for attempt in range(retries):
        _throttle()
        request = urllib.request.Request(
            url,
            headers={"User-Agent": _user_agent_for(url), "Accept-Encoding": "gzip"},
        )
        try:
            with urllib.request.urlopen(request, timeout=30) as response:
                body = response.read()
                if response.headers.get("Content-Encoding") == "gzip":
                    body = gzip.decompress(body)
                return body
        except urllib.error.HTTPError as error:
            last_error = error
            if error.code not in (429, 500, 502, 503, 504):
                raise FetchError(f"{url} -> HTTP {error.code}") from error
            retry_after = error.headers.get("Retry-After") if error.headers else None
            backoff = int(retry_after) if (retry_after or "").isdigit() else 2**attempt * 5
        except (urllib.error.URLError, TimeoutError) as error:
            last_error = error
            backoff = 2**attempt * 5

        if attempt < retries - 1:  # 最終試行のあとに待っても意味がない
            time.sleep(backoff)

    raise FetchError(f"{url} -> {last_error}")


_SUBMISSION_CODE_RE = re.compile(
    r'<pre[^>]*id="submission-code"[^>]*>(.*?)</pre>', re.DOTALL
)
_TAG_RE = re.compile(r"<[^>]+>")


def extract_submission_code(page_html: str) -> str:
    """提出ページの HTML からソースコード本文を取り出す。

    コードは <pre id="submission-code"> の中に、シンタックスハイライト用の <span> が
    挟まった状態で HTML エスケープされて入っている。先にタグを除去してからアンエスケープする
    （逆順にすると、コード中の `a < b` の `<` をタグの開始と誤認して本文を壊す）。
    """
    match = _SUBMISSION_CODE_RE.search(page_html)
    if match is None:
        raise FetchError("submission-code が見つからない（ページ構造が変わった可能性）")
    return html_mod.unescape(_TAG_RE.sub("", match.group(1)))


def pick_latest_ac(submissions: list[dict]) -> dict[str, dict]:
    """問題ごとに最新の AC 提出を 1 件だけ選ぶ。

    同じ問題を複数回 AC している場合、最後に通したものが現時点の実力を最もよく表すため。
    同時刻の AC が並んだ場合は id が大きい方を採る（結果を入力順に依存させないため）。
    """
    latest: dict[str, dict] = {}
    for submission in submissions:
        if submission["result"] != "AC":
            continue
        current = latest.get(submission["problem_id"])
        key = (submission["epoch_second"], submission["id"])
        if current is None or key > (current["epoch_second"], current["id"]):
            latest[submission["problem_id"]] = submission
    return latest


# 言語名 → 拡張子。AtCoder の language は "C++ 20 (gcc 12.2)" のような文字列なので、
# バージョン部分を落とした名前で完全一致させる。前方一致で引くと
# "JavaScript".startswith("Java") が成立して JS を Java と誤判定する（実際に踏んだ）。
_EXTENSION_BY_LANGUAGE = {
    "C++": ".cpp",
    "C": ".c",
    "C#": ".cs",
    "Java": ".java",
    "JavaScript": ".js",
    "TypeScript": ".ts",
    "Python": ".py",
    "PyPy": ".py",
    "Rust": ".rs",
    "Go": ".go",
    "Kotlin": ".kt",
    "Ruby": ".rb",
    "Bash": ".sh",
    "Text": ".txt",
}


def language_name(language: str) -> str:
    """"C++ 20 (gcc 12.2)" -> "C++"、"PyPy3 (7.3.0)" -> "PyPy" のように正規化する。"""
    head = language.split("(")[0]
    return re.sub(r"[\s\d.]+\Z", "", head)


def source_extension(language: str) -> str:
    """未知の言語は .txt に落とす（保存自体は成功させ、後段で気付けるようにする）。"""
    return _EXTENSION_BY_LANGUAGE.get(language_name(language), ".txt")


def problem_code_path(code_dir: Path, submission: dict) -> Path:
    """提出を保存するパスを決める。contest_id / problem_id は必ず検証する。"""
    for key in ("contest_id", "problem_id"):
        if not _SAFE_ID_RE.match(str(submission[key])):
            raise UnsafeIdError(f"{key}={submission[key]!r} は安全な識別子ではない")

    extension = source_extension(submission["language"])
    path = code_dir / submission["contest_id"] / f"{submission['problem_id']}{extension}"

    # 正規表現をすり抜ける経路が将来できても、書き込み先が code_dir の外に出ないことを保証する。
    if not path.resolve().is_relative_to(code_dir.resolve()):
        raise UnsafeIdError(f"{path} が {code_dir} の外を指している")
    return path


def write_atomic(path: Path, content: str | bytes) -> None:
    """一時ファイルに書いてから rename する。

    中断されたときに壊れた中身のファイルが残ると、レジューム時に「取得済み」と
    誤認してしまう。rename は同一ドライブ上でアトミックなのでこれを防げる。
    """
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(path.suffix + ".part")
    if isinstance(content, bytes):
        temporary.write_bytes(content)
    else:
        temporary.write_text(content, encoding="utf-8", newline="\n")
    temporary.replace(path)
