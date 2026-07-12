#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<vector<int>> g(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  const int INF=1e9;
  vector<int> cur(n+1,INF);//暫定距離を記録
  vector<bool> confirmed(n+1);//最短距離が確定した頂点
  auto dijkstra=[&](){
    priority_queue<pair<int,int>> pque;
    for(int i=0;i<k;i++){
      int p,h;
      cin>>p>>h;
      cur[p]=h;
      pque.push({h,p});
    }
    while(!pque.empty()){
      auto [c,u]=pque.top();
      pque.pop();
      if(confirmed[u]){// !確定済み頂点である間、キューの最小値を削除し続ける
        continue;// !これを入れないとO(M^2)になってしまうケースがありそう。
        // !実際に実験すると、下の*での確認だけでは、同じ頂点に対して複数の{コスト,頂点}の要素が入りうると分かる。
        // !これを入れないと同じ頂点に対してN回ループ処理することになり、ボトルネックになりうる。
        // !実験メモ
        // !完全グラフに対して、キューへのpushの時にコストが全部同じになるようにしてシミュレーション。
        // !キューの要素は合計で2M個になった。
        // !これらの要素全てについてN回調べると、2M+(2M-N)N回の計算をするため、O(NM)となる。
        // !この!での確認を行えば2M+log(MlogM)でconfirmを全て確定できる。
        // !よって全体でO(MlogM)になりそう。
      }
      confirmed[u]=true;
      for(auto v:g[u]){
        if(!confirmed[v]&&c>0){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          pque.push({c-1,v});//ヒープキューに暫定距離を入れつつ
          cur[v]=max(cur[v],c-1);//!暫定距離を更新していく
          //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          //!curは更新されるとは限らないことに注意
        }
      }
    }
  };
  dijkstra();
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(confirmed[i]){
      cnt++;
    }
  }
  cout<<cnt<<'\n';
  for(int i=1;i<=n;i++){
    if(confirmed[i]){
      cout<<i<<' ';
    }
  }
  return 0;
}