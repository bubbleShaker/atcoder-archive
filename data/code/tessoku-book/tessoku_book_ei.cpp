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
  vector<bool> isChecked(n+1);
  vector<int> ans;
  bool isEnd=false;
  auto dfs=[&](auto dfs,int u)->void{
    if(isChecked[u]){
      return;
    }
    isChecked[u]=true;
    if(u==n){
      isEnd=true;
      ans.push_back(u);
      return;
    }
    for(auto v:g[u]){
      dfs(dfs,v);
      if(isEnd){
        ans.push_back(u);
        return;
      }
    }
  };
  dfs(dfs,1);
  reverse(ans.begin(),ans.end());
  for(auto &&num:ans){
    cout<<num<<' ';
  }
}