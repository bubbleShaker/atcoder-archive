#include <bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;

set<int> st;
vector<bool> seen;

void dfs(const Graph &G,int u){
  seen[u]=true;
  if(G[u].size()==0){
    st.insert(u);
    return;
  }
  for(auto v:G[u]){
    if(!seen[v]){
      dfs(G,v);
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  Graph G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[b].push_back(a);
  }
  seen.assign(n,false);
  for(int i=0;i<n;i++){
    if(!seen[i]){
      dfs(G,i);
    }
  }
  if(st.size()==1){
    cout<<*(st.begin())+1<<endl;
  }else{
    cout<<-1<<endl;
  }
  return 0;
}