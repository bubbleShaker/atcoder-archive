#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> s(n),t(n);
  map<string,int> mp;
  for(int i=0;i<n;i++) cin>>s[i],cin>>t[i],mp[s[i]]++,mp[t[i]]++;
  for(int i=0;i<n;i++){
    if(mp[s[i]]==1||mp[t[i]]==1){
      //何もしない
    }else if(s[i]==t[i]&&mp[s[i]]==2){
      //何もしない
    }else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}