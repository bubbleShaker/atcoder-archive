#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;

int main(){
  int n,m;
  cin>>n>>m;
  set<P> st;
  int ans=0;
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    if(u>v){
      swap(u,v);
    }
    if(st.count(make_pair(u,v))){
      ans++;
    }else if(u==v){
      ans++;
    }else{
      st.insert(make_pair(u,v));
    }
  }
  cout<<ans<<endl;
  return 0;
}