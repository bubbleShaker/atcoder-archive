#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    cout<<i+1<<": {";
    int m=g[i].size();
    for(int j=0;j<m;j++){
      cout<<g[i][j]+1<<((j+1!=m)?",":"");
    }
    cout<<"}"<<'\n';
  }
}