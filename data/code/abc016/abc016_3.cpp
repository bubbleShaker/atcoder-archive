#include <bits/stdc++.h>
using namespace std;
using Graph=vector<set<int>>;

int main(){
  int n,m;
  cin>>n>>m;
  Graph G(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G[a].insert(b);
    G[b].insert(a);
  }
  vector<set<int>> st(n+1);
  for(int i=1;i<=n;i++){
    for(int j:G[i]){//j:iの友達
      for(int k:G[j]){//k:iの友達の友達
        if(!G[i].count(k)&&k!=i){//kがiの友達でない&&kがiでないならば追加
          st[i].insert(k);
        }
      }
    }
    cout<<(int)st[i].size()<<endl;
  }
  return 0;
}