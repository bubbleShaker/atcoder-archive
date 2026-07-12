#include <bits/stdc++.h>
using namespace std;
using P=pair<long long,long long>;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  map<P,vector<pair<long long,P>>> g;
  for(int i=0;i<m;i++){
    int u,v,a;
    cin>>u>>v>>a;
    if(a==0){
      g[{u,1}].push_back({1,{v,1}});
      g[{v,1}].push_back({1,{u,1}});
    }else{
      g[{u,0}].push_back({1,{v,0}});
      g[{v,0}].push_back({1,{u,0}});
    }
  }
  for(int i=1;i<=k;i++){
    int s;
    cin>>s;
    g[{s,0}].push_back({0,{s,1}});
    g[{s,1}].push_back({0,{s,0}});
  }
  const long long INF=1e18;
  map<P,long long> cur;//暫定距離を記録
  map<P,bool> confirmed;//最短距離が確定した頂点
  auto dijkstra=[&](){
    priority_queue<pair<long long,P>,vector<pair<long long,P>>,greater<pair<long long,P>>> hque;
    hque.push({0,{1,0}});
    cur[{1,0}]=0;
    while(!hque.empty()){
      auto [_,u]=hque.top();
      hque.pop();
      if(confirmed.count(u)){// !確定済み頂点である間、キューの最小値を削除し続ける
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
        if(!confirmed.count(v)){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          cur[v]=((cur.count(v))?min(cur[v],c+cur[u]):c+cur[u]);//!暫定距離を更新していく
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
  if(confirmed.count({n,0})){
    ans=min(ans,cur[{n,0}]);
  }
  if(confirmed.count({n,1})){
    ans=min(ans,cur[{n,1}]);
  }
  cout<<((ans!=INF)?ans:-1)<<'\n';
  return 0;
}