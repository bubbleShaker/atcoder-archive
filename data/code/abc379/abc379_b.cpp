#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int cnt=0;
  int ans=0;
  for(int i=0;i<n;i++){
    if(s[i]=='X'){
      ans+=cnt/k;
      cnt=0;
    }
    if(s[i]=='O'){
      cnt++;
    }
  }
  ans+=cnt/k;
  cout<<ans<<endl;
  return 0;
}