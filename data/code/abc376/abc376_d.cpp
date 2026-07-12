#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=1e9;
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
  }
  queue<int> que;
  vector<int> dist(n,INF);
  que.push(0);
  dist[0]=0;
  while(!que.empty()){
    int u=que.front();
    que.pop();
    for(int v:g[u]){
      if(dist[v]!=INF){
        continue;
      }
      dist[v]=dist[u]+1;
      que.push(v);
    }
  }
  int ans=INF;
  for(int u=0;u<n;u++){
    for(int i=0;i<g[u].size();i++){
      int v=g[u][i];
      if(v==0){
        ans=min(ans,dist[u]+1);
      }
    }
  }
  if(ans==INF){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
  return 0;
}