#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> g(n+1);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
  }
  const int INF=1e9;
  vector<int> cur(n+1,INF);//暫定距離を記録
  vector<bool> confirmed(n+1);//最短距離が確定した頂点
  auto dijkstra=[&](){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> hque;
    hque.push({0,1});
    cur[1]=0;
    while(!hque.empty()){
      auto [_,u]=hque.top();
      hque.pop();
      if(confirmed[u]){//確定済み頂点である間、キューの最小値を削除し続ける
        continue;//これを入れないとO(NM)になってしまうケースがありそう
      }
      confirmed[u]=true;
      for(auto [v,c]:g[u]){
        hque.push({c+cur[u],v});//ヒープキューに暫定距離を入れつつ
        cur[v]=min(cur[v],c+cur[u]);//暫定距離を更新していく
      }
    }
  };
  dijkstra();
  for(int i=1;i<=n;i++){
    if(cur[i]!=INF){
      cout<<cur[i]<<'\n';
    }else{
      cout<<-1<<'\n';
    }
  }
}