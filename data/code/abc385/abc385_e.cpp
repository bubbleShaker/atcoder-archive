#include <bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define pb push_back

int main(){
  const int INF=2e9;
  int N;
  cin>>N;
  Graph G(N+1);
  int de[N+1]={};
  for(int i=0;i<N-1;i++){
    int u,v;
    cin>>u>>v;
    G[u].pb(v);
    G[v].pb(u);
    de[u]++;
    de[v]++;
  }
  vector<vector<int>> deg(N+1);
  int ans=INF;
  int blu_cnt=0;
  for(int u=1;u<=N;u++){
    for(auto v:G[u]){
      deg[u].pb(de[v]);
    }
    sort(deg[u].rbegin(),deg[u].rend());
    for(int x=1;x<=deg[u].size();x++){
      blu_cnt++;
      int y=deg[u][x-1]-1;
      ans=min(ans,N-(1+x+x*y));
    }
  }
  cout<<ans<<endl;
  return 0;
}