#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  vector<string> ans;
  for(int i=0;i<k;i++) ans.push_back(s[i]);
  sort(ans.begin(),ans.end());
  for(int i=0;i<k;i++) cout<<ans[i]<<endl;
  return 0;
}