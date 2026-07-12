#include <bits/stdc++.h>
using namespace std;
struct Edge{
  long long to;
  long long cost;
};
using Graph=vector<vector<Edge>>;
const long long INF=1LL<<60;

vector<long long> ct;
void dfs(const Graph &G,int u){
  for(auto e:G[u]){
    if(ct[e.to]==INF){
      ct[e.to]=ct[u]+e.cost;
      dfs(G,e.to);
    }
  }
}

int main(){
  int N,M;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
    long long u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    G[u].push_back({v,w});
    G[v].push_back({u,-w});
  }
  
  ct.assign(N,INF);
  for(int i=0;i<N;i++){
    if(ct[i]==INF){
      ct[i]=0;
      dfs(G,i);
    }
  }
  for(int i=0;i<N;i++) cout<<ct[i]<<" ";
  cout<<endl;
  return 0;
}