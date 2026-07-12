#include <iostream>
#include <vector>
#include <numeric>
int main(){
  const long long MOD=(long long)1e9+7;
  int n;
  std::cin>>n;
  std::vector<long long> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  long long sum=std::accumulate(a.begin(),a.end(),0LL);
  long long ans=0;
  for(int i=0;i<n-1;i++){
    sum-=a[i];
    sum=(sum+MOD)%MOD;
    ans+=a[i]*sum;
    // std::cout<<ans<<'\n';
    ans%=MOD;
  }
  std::cout<<ans<<'\n';
  return 0;
}