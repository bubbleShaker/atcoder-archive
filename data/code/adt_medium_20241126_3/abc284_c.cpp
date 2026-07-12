#include <bits/stdc++.h>
using namespace std;
//参照:https://algo-logic.info/connected-components-num/

struct Edge{
  int to;
};
using Graph=vector<vector<Edge>>;

//深さ優先探索
vector<bool> seen; //探索したか記憶
void dfs(const Graph &G,int v){
  seen[v]=true;
  for(auto e:G[v]){
    if(!seen[e.to]){ //訪問済みでなければ探索
      dfs(G,e.to);
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
    G[a].push_back({b});
    G[b].push_back({a});
  }
  
  seen.assign(n,false);
  int cnt=0;
  for(int i=0;i<n;i++){
    if(!seen[i]){
      dfs(G,i);
      cnt++; //dfsした回数をカウント
    }
  }
  cout<<cnt<<endl;
  return 0;
}