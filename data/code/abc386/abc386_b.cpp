#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int ni=0;
  int ans=0;
  while(ni<s.size()){
    if(s[ni]=='0'){
      if(ni+1<s.size()&&s[ni+1]=='0'){
        ni+=2;
        ans++;
      }else{
        ni++;
        ans++;
      }
    }else{
      ni++;
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}