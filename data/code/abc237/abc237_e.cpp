#include <bits/stdc++.h>
using namespace std;
using P=pair<long long,long long>;
int main(){
  int n,m;
  cin>>n>>m;
  vector<long long> h(n+1);
  for(int i=1;i<=n;i++){
    cin>>h[i];
  }
  vector<vector<P>> g(n+1);
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    if(h[u]>h[v]){
      g[u].push_back({0,v});
      g[v].push_back({h[u]-h[v],u});
      // cerr<<h[u]-h[v]<<'\n';
    }else{
      g[u].push_back({h[v]-h[u],v});
      g[v].push_back({0,u});
      // cerr<<h[v]-h[u]<<'\n';
    }
  }
  const long long INF=1e18;
  vector<long long> cur(n+1,INF);//暫定距離を記録
  vector<bool> confirmed(n+1);//最短距離が確定した頂点
  auto dijkstra=[&](){
    priority_queue<P,vector<P>,greater<P>> hque;
    hque.push({0,1});
    cur[1]=0;
    while(!hque.empty()){
      auto [_,u]=hque.top();
      hque.pop();
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
      for(auto [c,v]:g[u]){
        if(!confirmed[v]){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          cur[v]=min(cur[v],c+cur[u]);//!暫定距離を更新していく
          //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          //!curは更新されるとは限らないことに注意
          hque.push({cur[v],v});//ヒープキューに暫定距離を入れつつ
        }
      }
    }
  };
  dijkstra();
  long long ans=INF;
  for(int i=1;i<=n;i++){
    ans=min(ans,cur[i]+h[i]-h[1]);
  }
  cout<<-ans<<'\n';
  return 0;
}