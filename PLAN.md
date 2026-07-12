# atcoder-archive — 提出コードを典型分類して Obsidian で管理する

## 目的

AtCoder ユーザー `Coji` の過去提出をローカルに保存し、アルゴリズムの「典型」で分類して
Obsidian Vault として管理する。復習と弱点の可視化（`atcoder-roadmap` の diff 1000-1200 の壁）に使う。

## 現状の実測値（2026-07-12 時点）

| 項目 | 値 |
| --- | --- |
| 全提出 | 3,493 件 |
| AC 提出 | 2,404 件 |
| ユニーク AC 問題 | 1,716 問 |
| 期間 | 2023-06-10 〜 2026-07-11 |
| 言語 | ほぼ C++（C 9件） |
| AC コード総量 | 約 2.8 MB |

## データ取得の方法（検証済み）

1. **提出メタデータ** — kenkoooo AtCoder Problems API v3
   `GET https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=Coji&from_second={t}`
   500 件ずつ返るので、最後の `epoch_second` を次の `from_second` にしてページングする。
   ソースコード本文は含まれない（メタデータのみ）。

2. **ソースコード本文** — atcoder.jp の提出ページをスクレイプ
   `GET https://atcoder.jp/contests/{contest_id}/submissions/{id}` の `<pre id="submission-code">`。
   - ログイン不要（終了済みコンテストの提出は公開）。
   - **ブラウザ相当の User-Agent が必須**。素の UA は 403 になる。
   - 1 req/秒 を厳守する（負荷をかけると IP 制限を受ける）。

3. **difficulty** — `https://kenkoooo.com/atcoder/resources/problem-models.json`
   全問題ぶんが 1 リクエストで取れる。問題ごとの個別取得は不要。

`atcoder-tools` / `online-judge-tools` はテストケース DL・提出用で、過去提出の回収機能は無い。

## 設計方針

**生データ層と Vault 層を分離する。**

```
atcoder-archive/
├── data/                      # ① 生データ（一度取ったら再取得しない）
│   ├── submissions.json
│   ├── problem-models.json    #   difficulty（生の IRT 値。表示には補正が要る）
│   ├── problems.json          #   問題タイトル
│   ├── contest-problem.json   #   問題 → 出題元コンテスト
│   ├── tags.json              #   M3 で Claude が確定させたタグ（M2 時点では無い）
│   └── code/{contest_id}/{problem_id}.cpp
├── tools/
│   ├── fetch_meta.py          # ② メタ取得
│   ├── fetch_code.py          # ③ コード取得（レジューム対応）
│   ├── classify.py            # ④ 静的解析でタグ候補
│   └── build_vault.py         # ⑤ Obsidian ノート生成
└── vault/problems/{problem_id}.md   # ⑥ Obsidian が開く Vault（git 追跡しない派生物）
```

理由:
- 分類のやり直しは必ず起きる（タグ体系は使いながら育つ）。生データを固めておけば、
  分類を作り直しても 1,716 回のダウンロードは二度と走らない。
- `vault/` は `build_vault.py` の出力する派生物。捨てて再生成できる状態を保つ。

## 取得範囲

- **AC のみ・1 問 1 提出**（各問題の最新 AC）。1,716 問、約 30 分。
- WA/TLE は `submissions.json` にメタだけ残る（後から「なぜ落ちたか」を分析したくなったら
  `fetch_code.py` の対象を広げれば取れる）。

## 分類方式

**静的解析 → Claude の 2 段。**

1. `classify.py` がコードから機械的にタグ候補を抽出する。**高精度・低再現率**の方針で、
   確実な証拠があるときだけ付ける（`priority_queue` があるだけではダイクストラにしない。
   優先度付きキューは貪欲でも使う）。結果、640 問に付き 1,076 問は未分類のまま残る。
2. Claude が問題文とコードを読んで典型名を確定し、`data/tags.json` に書く。静的解析では
   取れない構造的な典型（「二重ループの全探索」「貪欲」など）を埋める。M3 の成果を vault/ 側では
   なく data/ 側に置くことで、vault/ を「捨てて再生成できる派生物」のまま保つ。

**ルールは「宣言」ではなく「使用」を見ること。** 提出コードには共通テンプレートが貼られていて、
`vi dx = {...}, dy = {...};` `const ll MOD = 1000000007;` `using mint = modint998244353;` が
問題と無関係に常駐している。宣言に反応させると全問題にタグが付く（M2 で実際に踏んだ:
mod 検出 293 問のうち 213 問が宣言だけだった）。

## タグ体系：階層タグ

`#典型/DP/桁DP` のような**階層タグ**を使う（単一階層の `#DP` ではない）。
Obsidian のタグペインが木構造になり、「DP 全体は解けるが桁 DP だけ弱い」という粒度が見える。
`atcoder-roadmap` の弱点（diff 1000-1200 の壁）を掘るにはこの粒度が要る。

第 1 階層: `典型/探索` `典型/DP` `典型/グラフ` `典型/数学` `典型/データ構造` `典型/文字列`
`典型/貪欲` `典型/実装`

Vault は再生成できる派生物なので、タグ体系の作り直しは安い。M3 で全件を読んだ結果を踏まえて
見直してよい。

**APG4b（C++ 入門教材、27 問）は `#教材` タグで典型分類から外す**。文法練習であって
アルゴリズムではなく、集計に混ざると弱点分析が歪むため。tessoku-book（100 問）は典型そのもの
なので残す。

## マイルストーン

- [x] **M1** メタ取得 + コード取得（レジューム対応）→ `data/` に生データ … Issue #1 / PR #2
      1,716 問取得完了。詳細は `summary/01-m1-fetch.md`
- [x] **M2** 静的解析タグ + difficulty のマージ → Obsidian ノート生成 … Issue #3 / PR #5
      1,716 ノート生成。詳細は `summary/02-m2-vault.md`
- [ ] **M3** Claude による典型名の確定（バッチ処理）→ `data/tags.json`
- [ ] **M4** Dataview で「典型 × difficulty」の弱点ビュー

## 次にこの repo を開いたとき（セッション再開の入り口）

**まず手を動かす前に読むもの**: この PLAN.md → `summary/02-m2-vault.md`（M2 で踏んだ罠が全部ある）。
会話の記憶は無い前提で書いてある。

### 1. 未消化のタスク（M2 の宿題、Claude にはできない）

- **Obsidian でタグペインの階層表示を確認する。** `~/git/atcoder-archive/vault` を Vault として開き、
  タグペインに `典型 > データ構造 > set` の木が出るか見る。GUI が要るので人がやる。
  崩れていたら frontmatter の `tags` の書き方（`["典型/DP", …]` のフロー列）を直す。

### 2. M3 の着手手順

Issue を起票してから始める（`gh issue create`）。やることは
**「1,074 問の未分類 + 誤りのある候補タグを Claude が読んで確定させ、`data/tags.json` に書く」**。

- 受け皿は実装済み。`data/tags.json` に `{"abc305_c": ["典型/探索/幅優先探索"], …}` を置けば、
  `build_vault.py` がそれを `tags` に載せ、`tag_source: claude` を立てる。空リストは
  「典型なし」と確定した意味になる（キーの有無で判定している）。
  形が違えば `validate_confirmed_tags` が落とすので、壊れたまま気付かないことは無い。
- `data/tags.json` は**生データ層の一部として git 追跡する**（Claude が読んだ結果は再生成が高くつく）。
- 静的解析の結果は常に `auto_tags` に残るので、確定タグと突き合わせて監査できる。
- 現状のタグ分布は `python tools/classify.py` でいつでも出る。

**設計上まだ決めていないこと**（M3 の Issue で決める）:
- 問題文をどう入手するか（`data/` にはコードとメタしか無い。問題文のスクレイプが要るか、
  コードと難易度だけで typing できるか）。
- 1,716 問を Claude に読ませるバッチの粒度と、途中再開の方法（M1 と同じくレジューム前提にする）。
- 静的解析が付けた候補タグを Claude が「消す」ケースの扱い。

### 3. 触るときの不変条件（破ると設計が壊れる）

- `data/` は書き換えない。`vault/` は `build_vault.py` の派生物で、捨てて再生成できる（git 追跡しない）。
- 新しい取得スクリプトは必ず `common.http_get` を経由する（レート制限がその内部にある）。
- 静的解析ルールは「宣言」ではなく「使用」を見る（テンプレート常駐の `dx/dy`・`MOD`・`mint`）。
- テストは `python -m unittest discover -s tools -t tools`（93 件、ネットワーク不要）。

## 関連

- `~/git/atcoder-roadmap` — 学習戦略とロードマップ（本 repo の分類結果を根拠にする）
- `~/git/AtCoder` — 手元の解答コード
