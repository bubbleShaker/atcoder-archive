# M1: 提出コードのローカル取得（完了）

Issue #1 / PR #2 — 2026-07-12

## 何ができるようになったか

AtCoder ユーザー `Coji` の AC コード **1,716 問（各問題の最新 AC）がローカルに揃った**。
未取得 0 / 失敗 0 / 破損 0。

```
data/
├── submissions.json        # 全提出 3,493 件のメタデータ
├── problem-models.json     # difficulty 5,025 問ぶん（.gitignore、再取得可能）
└── code/{contest}/{problem}.{ext}
```

| 拡張子 | 問題数 |
| --- | --- |
| `.cpp` | 1,692 |
| `.cs` | 14 |
| `.java` | 4 |
| `.sh` | 4 |
| `.js` | 1 |
| `.c` | 1 |

再実行しても取得済みはスキップされる（レジューム）。`python tools/fetch_code.py` を
何度叩いても atcoder.jp に無駄なリクエストは飛ばない。

## 分かったこと（次に同じことをやる人へ）

- **提出のソースコード本文は API では取れない。** kenkoooo AtCoder Problems API が返すのは
  メタデータ（problem_id, language, result, length, exec_time …）だけ。本文は
  `https://atcoder.jp/contests/{contest}/submissions/{id}` の `<pre id="submission-code">`
  から取る必要がある。**ログインは不要**（終了済みコンテストの提出は公開されている）。
- **AtCoder は素の User-Agent に 403 を返す。** `python-urllib/3.12` のままでは弾かれる。
  ブラウザ相当を名乗る必要がある。一方 kenkoooo は識別可能な UA を求めているので、
  UA は接続先で出し分けている（`common.py: _user_agent_for`）。
- `atcoder-tools` / `online-judge-tools` はテストケース DL・提出用で、**過去提出の回収機能は無い**。
- kenkoooo API v3 は 1 リクエスト 500 件上限。`from_second` を進めてページングするが、
  **同じ秒に複数の提出があるため +1 して進めると取りこぼす**。同じ秒から取り直して id で
  重複排除している。

## レビューで見つかった実データのバグ

**`JavaScript (Node.js)` の提出が `.java` として保存される。**
言語判定を `startswith` の前方一致でやっていたため、`"JavaScript".startswith("Java")` が
成立していた。フル取得の前に気付けたので手戻りゼロ。

修正は「JavaScript を特例扱いする」のではなく、**前方一致という構造をやめて、バージョンを
落とした完全一致にした**（`"C++ 20 (gcc 12.2)"` → `"C++"`）。結果として `Java8` / `Python3` /
`PyPy2` のような未検証の言語名まで巻き込みで正しくなった。

もう 1 件、外部由来の `contest_id` / `problem_id` を無検証でファイルパスに使っていた
（パストラバーサル）。ホワイトリスト検証 + `resolve().is_relative_to()` の二重チェックを入れた。

## 設計の骨格（M2 以降も守ること）

**生データ層（`data/`）と Vault 層（`vault/`）を分離する。**

タグ体系は使いながら必ず育つので、分類は何度もやり直す。生データを別層に固めておけば、
**分類をやり直しても 1,716 回のダウンロードは二度と走らない**。`vault/` は
`build_vault.py` の出力する派生物であり、捨てて再生成できる状態を保つ。

もう一つ、**レート制限は `http_get` の内部に閉じ込めてある**（呼び出し側の `sleep` に頼らない）。
新しいスクリプトが `sleep` を書き忘れた瞬間に atcoder.jp を叩き放題になる、という経路を
構造的に消すため。新しい取得スクリプトを足すときも `http_get` を経由すること。
