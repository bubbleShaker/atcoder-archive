#include <bits/stdc++.h>
using namespace std;
int main(){
  const int INF=1e9;
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> dist(n+1,-INF);
  auto bfs=[&](){
    queue<int> que;
    que.push(1);
    dist[1]=0;
    while(!que.empty()){
      int u=que.front();
      que.pop();
      for(auto v:g[u]){
        if(dist[v]!=-INF){
          continue;
        }
        dist[v]=dist[u]+1;
        que.push(v);
      }
    }
  };
  bfs();
  for(int i=1;i<=n;i++){
    if(dist[i]!=-INF){
      cout<<dist[i]<<endl;
    }else{
      cout<<-1<<endl;
    }
  }
}