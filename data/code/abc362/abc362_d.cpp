#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<long long> a(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  std::vector<std::vector<std::pair<long long,int>>> g(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    long long b;
    std::cin>>u>>v>>b;
    g[u].push_back({b,v});
    g[v].push_back({b,u});
  }
  const long long INF=1e18;
  auto dijkstra=[&](int start){
    std::vector<long long> cur(n+1,INF);//暫定距離を記録
    std::vector<bool> confirmed(n+1);//最短距離が確定した頂点
    std::priority_queue<std::pair<long long,int>,std::vector<std::pair<long long,int>>,std::greater<std::pair<long long,int>>> hque;
    hque.push({a[start],start});
    cur[start]=a[start];
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
          cur[v]=std::min(cur[v],c+cur[u]+a[v]);//!暫定距離を更新していく
          //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          //!curは更新されるとは限らないことに注意
          hque.push({cur[v],v});//ヒープキューに暫定距離を入れつつ
        }
      }
    }
    return cur;
  };
  std::vector<long long> cur=dijkstra(1);
  for(int i=2;i<=n;i++){
    std::cout<<cur[i]<<((i!=n)?' ':'\n');
  }
  return 0;
}