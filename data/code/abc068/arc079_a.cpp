#include <iostream>
#include <vector>
#include <queue>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<std::vector<int>> g(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    std::cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  const int INF=1e9;
  std::vector<int> dist(n+1,INF);
  auto bfs=[&](){
    std::queue<int> que;
    que.push(1);
    dist[1]=0;
    while(!que.empty()){
      int u=que.front();
      que.pop();
      for(auto v:g[u]){
        if(dist[v]!=INF){
          continue;
        }
        dist[v]=dist[u]+1;
        que.push(v);
      }
    }
  };
  bfs();
  if(dist[n]==2){
    std::cout<<"POSSIBLE"<<'\n';
  }else{
    std::cout<<"IMPOSSIBLE"<<'\n';
  }
  return 0;
}