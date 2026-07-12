#include <bits/stdc++.h>
using namespace std;
int main(){
  const long long INF=1e18;
  long long n,m;
  cin>>n>>m;
  vector<vector<tuple<long long,long long,long long>>> g(n+1);
  for(int i=0;i<m;i++){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    g[a].push_back({c,d,b});
    g[b].push_back({c,d,a});
  }
  auto floorll=[&](long long a,long long b){
    return a/b;
  };
  auto calc=[&](long long c,long long d,long long t){
    return c+floorll(d,1+t);
  };
  auto bestTimeCalc=[&](long long c,long long d){
    long long mi=INF;
    long long ret;
    long long dsqrt=sqrt((double)d);
    for(long long t=dsqrt-2;t<=dsqrt+2;t++){
      if(t<0){
        continue;
      }
      if(t+calc(c,d,t)<mi){
        ret=t;
        mi=t+calc(c,d,t);
      }
    }
    return ret;
  };
  vector<long long> cur(n+1,INF);//暫定距離を記録
  vector<bool> confirmed(n+1);//最短距離が確定した頂点
  auto dijkstra=[&](){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> hque;
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
      for(auto [c,d,v]:g[u]){
        if(!confirmed[v]){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          long long bestTime=bestTimeCalc(c,d);
          // cerr<<bestTime<<'\n';
          if(cur[u]<=bestTime){
            cur[v]=min(cur[v],bestTime+calc(c,d,bestTime));
          }else{
            cur[v]=min(cur[v],cur[u]+calc(c,d,cur[u]));
          }
          // cerr<<cur[v]<<'\n';
          hque.push({cur[v],v});//ヒープキューに暫定距離を入れつつ
          // cur[v]=min(cur[v],c+cur[u]);//!暫定距離を更新していく
          // //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          // //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          // //!curは更新されるとは限らないことに注意
        }
      }
    }
  };
  dijkstra();
  // for(int i=1;i<=n;i++){
  //   cout<<cur[i]<<'\n';
  // }
  cout<<((cur[n]!=INF)?cur[n]:-1)<<'\n';
  return 0;
}