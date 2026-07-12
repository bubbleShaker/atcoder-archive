#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  set<int> st;
  for(int i=0;i<m;i++){
    int a;
    cin>>a;
    st.insert(a);
  }
  vector<int> ans;
  for(int i=1;i<=n;i++){
    if(!st.count(i))ans.push_back(i);
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;
}