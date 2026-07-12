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
  int maIdx;
  int maDeg=0;
  for(int i=1;i<=n;i++){
    if(maDeg<g[i].size()){
      maDeg=g[i].size();
      maIdx=i;
    }
  }
  cout<<maIdx<<'\n';
}