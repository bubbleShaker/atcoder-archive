#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=0;
  auto yakusuCnt=[&](int val){
    int ret=0;
    for(int i=1;i<=val;i++){
      if(val%i==0){
        ret++;
      }
    }
    return ret;
  };
  for(int i=1;i<=n;i++){
    if(i%2&&yakusuCnt(i)==8){
      ans++;
    }
  }
  cout<<ans<<'\n';
  return 0;
}