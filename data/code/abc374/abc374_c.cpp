#include <bits/stdc++.h>
using namespace std;

int main(){
  long long INF=1e18;
  int n;
  cin>>n;
  vector<long long> k(n);
  for(int i=0;i<n;i++){
    cin>>k[i];
  }
  long long sum=accumulate(k.begin(),k.end(),0LL);
  long long ans=INF;
  for(int i=0;i<(1<<n);i++){
    bitset<20> bs(i);
    long long tmp_sum=0;
    for(int j=0;j<n;j++){
      if(bs[j]){
        tmp_sum+=k[j];
      }
    }
    ans=min(ans,max(tmp_sum,sum-tmp_sum));
  }
  cout<<ans<<endl;
  return 0;
}