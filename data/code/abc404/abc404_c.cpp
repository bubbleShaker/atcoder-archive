#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  int n,m;
  cin>>n>>m;
  dsu uf(n);
  vector<int> deg(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    deg[u]++;
    deg[v]++;
    uf.merge(u,v);
  }
  set<int> st;
  for(int i=0;i<n;i++){
    if(deg[i]!=2){
      cout<<"No"<<endl;
      return 0;
    }
    st.insert(uf.leader(i));
  }
  if(st.size()==1){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}