#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=0;
  auto keta=[&](int val){
    int ret=0;
    while(val>0){
      val/=10;
      ret++;
    }
    return ret;
  };
  for(int i=1;i<=n;i++){
    if(keta(i)%2){
      ans++;
    }
  }
  cout<<ans<<'\n';
  return 0;
}