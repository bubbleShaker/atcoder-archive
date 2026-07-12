#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<string> s(n),t(m);
  set<string> st;
  for(int i=0;i<n;i++) cin>>s[i];
  for(int i=0;i<m;i++) cin>>t[i],st.insert(t[i]);
  int ans=0;
  for(int i=0;i<n;i++){
    string sb=s[i].substr(3);
    if(st.count(sb)) ans++;
  }
  cout<<ans<<endl;
  return 0;
}