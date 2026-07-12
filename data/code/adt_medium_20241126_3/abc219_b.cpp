#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> s(4);
  string t;
  for(int i=1;i<=3;i++) cin>>s[i];
  cin>>t;
  string ans;
  for(int i=0;i<t.size();i++) ans+=s[t[i]-'0'];
  cout<<ans<<endl;
  return 0;
}