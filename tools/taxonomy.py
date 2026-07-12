"""M3 のタグ語彙（data/taxonomy.json）を読み、タグの妥当性を検査する。

語彙を閉じておくのは、バッチごとに独立したコンテキストで走る Claude が
`典型/探索/全探索` と `典型/探索/全列挙` を勝手に作り分けるのを防ぐため。
乱立に気付いてから直すには 1,716 問を読み直すことになる。付け方の規範
（葉だけを付ける・紛らわしいペアの判断基準）は taxonomy.json の note 側にある。

- merge_tags.py … shard を tags.json に集約する前に、ここで語彙外タグを弾く
- test_taxonomy.py … classify.py のルールが語彙から外れていないかを検査する

build_vault.py の validate_confirmed_tags / load_confirmed_tags と同じく、
純粋な検証（parse_taxonomy）と IO（load_taxonomy）を分けている。壊れた語彙ファイルの
テストを monkeypatch 無しで書けるようにするため。
"""

from __future__ import annotations

import functools
import json
from collections.abc import Iterable
from pathlib import Path

from common import DATA_DIR

TAXONOMY_PATH = DATA_DIR / "taxonomy.json"
SCHEMA_VERSION = 1
TYPICAL_PREFIX = "典型/"
# `典型/DP` と `典型/DP/bitDP` の 2 段まで。`典型/DP/bitDP/さらに` は語彙側で閉じる。
MAX_DEPTH = 3


class TaxonomyError(ValueError):
    """語彙ファイルが壊れている。"""


def _check_tag_list(raw: object, key: str, *, prefix: str | None) -> list[str]:
    if not isinstance(raw, list) or not all(isinstance(v, str) for v in raw):
        raise TaxonomyError(f"{key} は文字列のリストでなければならない")
    if len(set(raw)) != len(raw):
        raise TaxonomyError(f"{key} にタグの重複がある")

    for tag in raw:
        segments = tag.split("/")
        # 空文字や `典型//DP` のような壊れたタグは、型だけ見る build_vault の
        # validate_confirmed_tags を素通りして frontmatter に出てしまう。ここで止める。
        if not tag or any(not segment for segment in segments):
            raise TaxonomyError(f"{key} に空のセグメントを含むタグがある: {tag!r}")
        if len(segments) > MAX_DEPTH:
            raise TaxonomyError(f"{key} のタグが深すぎる（最大 {MAX_DEPTH} 段）: {tag!r}")
        if prefix is not None and not tag.startswith(prefix):
            raise TaxonomyError(f"{key} のタグは {prefix!r} で始まらなければならない: {tag!r}")
    return list(raw)


def parse_taxonomy(raw: object) -> dict[str, list[str]]:
    """語彙データ（JSON をロードした結果）を検証して返す。IO はしない。"""
    if not isinstance(raw, dict):
        raise TaxonomyError("taxonomy はオブジェクトでなければならない")
    if raw.get("version") != SCHEMA_VERSION:
        raise TaxonomyError(f"未知の version: {raw.get('version')!r}（期待は {SCHEMA_VERSION}）")

    typical = _check_tag_list(raw.get("typical"), "typical", prefix=TYPICAL_PREFIX)
    excluded = _check_tag_list(raw.get("excluded"), "excluded", prefix=None)

    # note はタグ付けの規約そのもので、batch_tags.py がプロンプトに載せる。空だと 18 バッチが
    # 規約なしで走ってしまうので、飾りではなく必須項目として検証する。
    note = raw.get("note")
    if not isinstance(note, list) or not note or not all(isinstance(line, str) for line in note):
        raise TaxonomyError("note は空でない文字列のリストでなければならない")

    overlap = set(typical) & set(excluded)
    if overlap:
        raise TaxonomyError(f"typical と excluded に同じタグがある: {sorted(overlap)}")
    return {"typical": typical, "excluded": excluded, "note": note}


def load_taxonomy(path: Path = TAXONOMY_PATH) -> dict[str, list[str]]:
    """taxonomy.json を読む。手編集を前提にしているので、構文エラーも TaxonomyError に畳む。"""
    try:
        raw = json.loads(path.read_text(encoding="utf-8-sig"))
    except FileNotFoundError as exc:
        raise TaxonomyError(f"語彙ファイルが無い: {path}") from exc
    except json.JSONDecodeError as exc:
        raise TaxonomyError(f"語彙ファイルの JSON が壊れている: {path}: {exc}") from exc
    return parse_taxonomy(raw)


@functools.lru_cache(maxsize=1)
def confirmable_tags() -> frozenset[str]:
    """M3 の Claude が確定タグとして付けてよいタグ（典型のみ）。

    除外タグ（教材・ヒューリスティック）を含めないのが肝心。これらは contest_id から
    機械的に決まるもので、Claude が判断してはいけない（taxonomy.json の note を参照）。
    語彙にあるからと `allowed_tags()` で検証すると、バッチが `["教材"]` と書いても通ってしまう。

    1,716 問ぶんの検査で毎回ファイルを読み直さないようキャッシュする。frozenset なのは
    呼び出し元がキャッシュを破壊的に触れないようにするため。語彙ファイルを書き換えたら
    `confirmable_tags.cache_clear()` が要る（merge_tags は毎回新プロセスなので不要）。
    """
    return frozenset(load_taxonomy()["typical"])


@functools.lru_cache(maxsize=1)
def allowed_tags() -> frozenset[str]:
    """語彙に載っているタグの全集合（典型 + 除外系）。

    「Vault に出てよいタグ」の集合であって「Claude が付けてよいタグ」ではない。
    確定タグの検証には confirmable_tags() を使うこと。
    """
    taxonomy = load_taxonomy()
    return frozenset(taxonomy["typical"]) | frozenset(taxonomy["excluded"])


def unknown_tags(tags: Iterable[str], *, confirmable_only: bool = True) -> list[str]:
    """語彙に無いタグを返す。空リストなら妥当。

    既定は confirmable（典型のみ）。M3 の shard 検証がこの関数の主な用途で、そこでは
    除外タグを弾きたいため。静的解析の出力を検査するときだけ confirmable_only=False にする。
    """
    known = confirmable_tags() if confirmable_only else allowed_tags()
    return [tag for tag in tags if tag not in known]


def main() -> None:
    """語彙の統計を出す（手で 1 行足した後の確認用）。"""
    taxonomy = load_taxonomy()
    print(f"典型タグ: {len(taxonomy['typical'])} 個 / 除外タグ: {len(taxonomy['excluded'])} 個")
    for tag in taxonomy["typical"]:
        if tag.count("/") == 1:
            children = [t for t in taxonomy["typical"] if t.startswith(f"{tag}/")]
            print(f"  {tag:<12} 子 {len(children)} 個")


if __name__ == "__main__":
    main()
