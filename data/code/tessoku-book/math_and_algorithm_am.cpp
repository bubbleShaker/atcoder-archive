#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> isChecked(n+1,false);
  auto dfs=[&](auto dfs,int u)->void{
    if(isChecked[u]){
      return;
    }
    isChecked[u]=true;
    for(auto v:g[u]){
      dfs(dfs,v);
    }
  };
  dfs(dfs,1);
  for(int i=1;i<=n;i++){
    if(!isChecked[i]){
      cout<<"The graph is not connected."<<'\n';
      return 0;
    }
  }
  cout<<"The graph is connected."<<'\n';
}