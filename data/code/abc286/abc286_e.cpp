#include <bits/stdc++.h>
using namespace std;
int main(){
  const long long INF=1e9;
  long long n;
  cin>>n;
  vector<long long> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<vector<pair<pair<long long,long long>,long long>>> g(n+1);
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(s[i][j]=='Y'){
        g[i+1].push_back({{1,-a[j+1]},j+1});
      }
    }
  }
  vector<pair<long long,long long>> cur(n+1,{INF,0});//暫定距離を記録
  vector<bool> confirmed(n+1);//最短距離が確定した頂点
  auto add=[&](pair<long long,long long> p1,pair<long long,long long> p2){
    return pair<long long,long long>(p1.first+p2.first,p1.second+p2.second);
  };
  auto dijkstra=[&](long long start){
    priority_queue<pair<pair<long long,long long>,long long>,vector<pair<pair<long long,long long>,long long>>,greater<pair<pair<long long,long long>,long long>>> hque;
    hque.push({{0,-a[start]},start});
    cur[start]={0,-a[start]};
    while(!hque.empty()){
      auto [p,u]=hque.top();
      hque.pop();
      // cerr<<p.first<<" "<<-p.second<<" "<<u<<'\n';
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
      for(auto [pp,v]:g[u]){
        if(!confirmed[v]){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          cur[v]=min(cur[v],add(p,pp));//!暫定距離を更新していく
          //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          //!curは更新されるとは限らないことに注意
          hque.push({cur[v],v});//ヒープキューに暫定距離を入れつつ
        }
      }
    }
  };
  vector<vector<pair<long long,long long>>> ans(n+1,vector<pair<long long,long long>>(n+1,{INF,0}));
  for(int i=1;i<=n;i++){
    cur.clear();
    confirmed.clear();
    cur.resize(n+1,{INF,0});
    confirmed.resize(n+1,false);
    dijkstra(i);
    for(int j=1;j<=n;j++){
      if(!confirmed[j]){
        continue;
      }
      ans[i][j]=cur[j];
    }
  }
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    long long u,v;
    cin>>u>>v;
    if(ans[u][v].first==INF){
      cout<<"Impossible"<<'\n';
    }else{
      cout<<ans[u][v].first<<" "<<-ans[u][v].second<<'\n';
    }
  }
  return 0;
}