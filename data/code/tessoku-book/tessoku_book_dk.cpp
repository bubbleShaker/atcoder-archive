#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int> av(n+1,1),bv(n+1,1);
  for(int i=2;i<=n;i++){
    if(s[i-2]=='A'){
      av[i]+=av[i-1];
    }
  }
  for(int i=n-1;i>=1;i--){
    if(s[i-1]=='B'){
      bv[i]+=bv[i+1];
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=max(av[i],bv[i]);
  }
  cout<<ans<<endl;
  return 0;
}