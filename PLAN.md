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
│   ├── problem-models.json
│   └── code/{contest_id}/{problem_id}.cpp
├── tools/
│   ├── fetch_meta.py          # ② メタ取得
│   ├── fetch_code.py          # ③ コード取得（レジューム対応）
│   ├── classify.py            # ④ 静的解析でタグ候補
│   └── build_vault.py         # ⑤ Obsidian ノート生成
└── vault/problems/{problem_id}.md   # ⑥ Obsidian が開く Vault
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

1. `classify.py` がコードから機械的にタグ候補を抽出（`priority_queue` → ダイクストラ候補、
   `dp[` → DP 候補、など）。全件に即座に付く。
2. Claude が問題文とコードを読んで典型名を確定する。静的解析では取れない構造的な典型
   （「二重ループの全探索」「貪欲」など）を埋める。

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
- [ ] **M2** 静的解析タグ + difficulty のマージ → Obsidian ノート生成 … Issue #3
- [ ] **M3** Claude による典型名の確定（バッチ処理）
- [ ] **M4** Dataview で「典型 × difficulty」の弱点ビュー

## 関連

- `~/git/atcoder-roadmap` — 学習戦略とロードマップ（本 repo の分類結果を根拠にする）
- `~/git/AtCoder` — 手元の解答コード
