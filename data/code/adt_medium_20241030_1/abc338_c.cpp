#include <bits/stdc++.h>
using namespace std;

int main(){
  const long long INF=1e9;
  long long n;
  cin>>n;
  vector<long long> q(n),a(n),b(n);
  for(long long i=0;i<n;i++){
    cin>>q[i];
  }
  for(long long i=0;i<n;i++){
    cin>>a[i];
  }
  for(long long i=0;i<n;i++){
    cin>>b[i];
  }
  long long ans=0;
  for(long long i=0;i<=(long long)1e6;i++){
    long long b_cnt=INF;
    bool is_ok=true;
    for(long long j=0;j<n;j++){
      long long rem=q[j]-a[j]*i;
      if(rem<0){
        is_ok=false;
        break;
      }
      if(b[j]!=0){
        b_cnt=min(b_cnt,rem/b[j]);
      }
    }
    if(b_cnt==INF){
      b_cnt=0;
    }
    if(is_ok){
      ans=max(ans,i+b_cnt);
    }
  }
  cout<<ans<<endl;
  return 0;
}