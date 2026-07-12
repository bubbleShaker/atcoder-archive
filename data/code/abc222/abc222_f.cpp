#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<pair<long long,int>>> g(n+1);
  for(int i=1;i<=n-1;i++){
    int a,b;
    long long c;
    cin>>a>>b>>c;
    g[a].push_back({c,b});
    g[b].push_back({c,a});
  }
  vector<long long> d(n+1);
  for(int i=1;i<=n;i++){
    cin>>d[i];
  }
  const long long INF=1e18;
  auto dijkstra=[&](int start){
    vector<long long> cur(n+1,-INF);//暫定距離を記録
    vector<bool> confirmed(n+1);//最短距離が確定した頂点
    priority_queue<pair<long long,int>> pque;
    pque.push({0,start});
    cur[start]=0;
    while(!pque.empty()){
      auto [_,u]=pque.top();
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
      for(auto [c,v]:g[u]){
        if(!confirmed[v]){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          cur[v]=max(cur[v],c+cur[u]);//!暫定距離を更新していく
          //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          //!curは更新されるとは限らないことに注意
          pque.push({cur[v],v});//ヒープキューに暫定距離を入れつつ
        }
      }
    }
    return cur;
  };
  int s,t; //s,tは直径の両端のノード
  vector<long long> ds=dijkstra(1); //適当な頂点からダイクストラをして、そこからの最大コストを持つ頂点sを決める。
  // *木のある頂点からの最大距離を持つ頂点は、直径のノードのどちらかになるので、sは直径のノードの片方となる
  long long cost=-1; //costが最大のノードを探すので、costは取り得ない数にしておく。
  for(int i=1;i<=n;i++){
    if(i==1){
      continue;
    }
    if(cost<ds[i]+d[i]){
      cost=ds[i]+d[i];
      s=i;
    }
  }
  vector<long long> dt=dijkstra(s);
  cost=-1;
  for(int i=1;i<=n;i++){
    if(i==s){
      continue;
    }
    if(cost<dt[i]+d[i]){
      cost=dt[i]+d[i];
      t=i;
    }
  }
  vector<long long> cur1=dijkstra(s);
  vector<long long> cur2=dijkstra(t);
  for(int i=1;i<=n;i++){
    long long ans=-1;
    if(i!=s){
      ans=max(ans,cur1[i]+d[s]);
    }
    if(i!=t){
      ans=max(ans,cur2[i]+d[t]);
      
    }
    cout<<ans<<'\n';
  }
  return 0;
}