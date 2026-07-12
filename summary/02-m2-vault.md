# M2: Obsidian Vault の生成（完了）

Issue #3 — 2026-07-12

## 何ができるようになったか

`data/` の生データから **1,716 枚の Obsidian ノートが生成できる**ようになった。
`python tools/build_vault.py` を叩けば `vault/problems/{problem_id}.md` が揃う。何度実行しても
同じ結果になり（検証済み）、対象から外れた古いノートは削除される。

```markdown
---
problem_id: "abc305_c"
contest: "abc305"
title: "Snuke the Cookie Picker"
diff: 159
diff_experimental: false
result: "AC"
date: 2024-11-27
lang: "C++"
length: 687
exec_time: 6
tags: []                # Obsidian が読む確定タグ
auto_tags: []           # 静的解析の候補（M3 が上書きしても監査できるよう常に残す）
tag_source: "auto"      # auto | claude
url: "https://atcoder.jp/contests/abc305/tasks/abc305_c"
---
```

構造化データは全て frontmatter に置いた。M4 の Dataview で「典型 × difficulty」の表を
自由に組めるようにするため（本文にタグを散らすと集計できない）。

## タグの現状

静的解析で **642 問にタグが付き、1,074 問（63%）は未分類**のまま残っている。これは想定どおり。
`priority_queue` があるだけでダイクストラと決めつけるようなことはせず、**確実な証拠があるときだけ
付ける**方針を採ったため（高精度・低再現率）。残りは M3 で Claude が問題文を読んで埋める。
`典型/貪欲` と `典型/実装` は原理的にコードの見た目から判定できないので、静的解析では扱わない。

| タグ | 問題数 |
| --- | --- |
| 典型/データ構造/set | 184 |
| 典型/データ構造/map | 139 |
| 典型/DP | 83 |
| 典型/探索/二分探索 | 57 |
| 典型/数学/mod演算 | 51 |
| 典型/探索/深さ優先探索 | 48 |
| 典型/グラフ | 44 |
| 典型/探索/幅優先探索 | 40 |
| 典型/データ構造/グリッド | 39 |
| 典型/データ構造/priority_queue | 35 |
| （以下 18 種） | … |
| 教材（APG4b） | 27 |

## 実データで踏んだ罠（次に触る人へ）

**1. difficulty は生の IRT 値で、そのままでは使えない。**
`problem-models.json` の `difficulty` は易しい問題で負になる（`abc138_a` は **-848**）。
AtCoder Problems の表示値に合わせて 400 未満に `400 / exp(1 - d/400)` の補正が要る。
補正しないと「diff 1000-1200 の壁」を見るための軸そのものが壊れる。

**2. 提出時の `contest_id` は出題元コンテストではない。**
`abc305_c` の最新 AC は ADT（AtCoder Daily Training）での提出で、`contest_id` は
`adt_medium_20241127_1` だった。この手の解き直しが **111 問**ある。放置すると ABC/ARC 別の
集計が壊れるので、`contest-problem.json` から出題元に寄せ直している。

- **開催日時では選べない**。`abs`・`practice`・`tessoku-book` は `start_epoch_second` が 0 で、
  「最も古いコンテスト」を採ると `abc086_a` の出題元が `abs` になってしまう。
  problem_id が出題元コンテスト ID を接頭辞に持つ規則（`abc305_c` → `abc305`）で選んでいる。
- `problems.json` の `contest_id` も同じ理由で信用してはいけない（再出題コンテストを指す）。
  タイトルの取得にだけ使う。しかも `title` は `"E. Snuke the Cookie Picker"` と接頭辞付きなので
  `name` を使う。
- **問題ページは出題元、提出ページは提出時のコンテスト**で URL を組む。提出は ADT 配下にしか無い。

**3. 静的解析のルールは「宣言」ではなく「使用」を見ること。**
提出コードの先頭には 3 年ぶんの共通テンプレートが貼られていて、
`vi dx = {-1,0,1,0}, dy = {0,1,0,-1};` `const ll MOD = 1000000007;` `using mint = modint998244353;`
が問題と無関係に常駐している。最初の実装は宣言に反応していたため、**mod 検出 293 問のうち
213 問（73%）が誤検知**、グリッドも 299 問中ほとんどがテンプレート由来だった。
「`% MOD` という演算がある」「`dx[k]` と添字で引いている」に直して 51 問 / 39 問に落ち着いた。
`tools/test_classify.py: TemplateFalsePositiveTest` が回帰を防いでいる。

**4. `date` を引用符付きで書くと Dataview で日付比較できない。**
`date: "2023-06-10"` は YAML の型が文字列になる。裸で書けば日付型になる（M4 で効く）。

**5. 部分実行（`--limit`）で古いノートを消してはいけない。**
`prune_stale_notes` は「今回書かなかった = 対象外になった」という前提に立つが、`--limit 5` では
その前提が崩れて残り 1,711 枚が消える。動作確認のつもりで打った `--limit` が Vault を全消しする
ことになる（レビューで発見）。`should_prune` で全件実行のときだけ消すようにした。コードが未取得の
問題があるときも同じ理由で消さない。

## 設計上の判断

- **M3 の成果は `vault/` ではなく `data/tags.json` に置く。** `build_vault.py` がそれを読んで
  `tags` にマージし、`tag_source: claude` を立てる。こうすると `vault/` は最後まで
  「捨てて再生成できる派生物」のままでいられる（M1 から守っている骨格）。
- **`vault/problems/` は git 追跡しない。** 中身は `data/code` のコードの複製 + frontmatter なので、
  追跡するとコードを二重管理することになり、タグ体系を変えるたびに 1,716 ファイルぶんの
  diff が出てレビューが読めなくなる。`data/` があれば誰でも再生成できる。
  ただし `vault/.obsidian/`（Obsidian の設定）は追跡する。再生成できない唯一の資産で、
  タグペインやグラフの表示設定がここに入る。理由は PLAN.md の「セッション再開の入り口」§1。

## 残っていること

- タイトル不明 2 問（`ahc025_b` / `ahc027_b`。AHC の一部は `problems.json` に無い）。problem_id で代用。
- difficulty 不明 200 問（`problem-models.json` に推定値が無い問題。`diff: null`）。
