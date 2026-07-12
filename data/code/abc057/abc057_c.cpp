#include <bits/stdc++.h>
using namespace std;
int main(){
  const int INF=1e9;
  long long n;
  cin>>n;
  auto keta=[&](long long val){
    int ret=0;
    while(val>0){
      val/=10;
      ret++;
    }
    return ret;
  };
  auto F=[&](long long a,long long b){
    return max(keta(a),keta(b));
  };
  int ans=INF;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      ans=min(ans,F(i,n/i));
    }
  }
  cout<<ans<<'\n';
  return 0;
}