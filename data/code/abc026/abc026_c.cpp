#include <bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;

int n;
Graph G;
vector<int> memo;

int dfs(int u){
  if(memo[u]!=-1)return memo[u];
  if(G[u].size()==0)return 1;
  set<int> st;
  for(auto v:G[u]){
    st.insert(dfs(v));
  }
  return *st.begin()+*st.rbegin()+1;
}

int main(){
  cin>>n;
  G.resize(n+1);
  memo.assign(n+1,-1);
  for(int i=2;i<=n;i++){
    int b;
    cin>>b;
    G[b].push_back(i);
  }
  cout<<dfs(1)<<endl;
  return 0;
}