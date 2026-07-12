#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int a,b;
  cin>>a>>b;
  map<string,int> mp;
  mp[s]=a;
  mp[t]=b;
  string u;
  cin>>u;
  mp[u]--;
  cout<<mp[s]<<" "<<mp[t]<<endl;
  return 0;
}