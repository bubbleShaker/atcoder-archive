#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,K;
  cin>>n>>K;
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int k=K-(i+j);
      if(1<=k&&k<=n){
        ans++;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}