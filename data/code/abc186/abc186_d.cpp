#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  const long long INF=1e18;
  long long n;
  std::cin>>n;
  std::vector<long long> a(n+1,-INF);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  std::sort(a.begin(),a.end());
  std::vector<long long> rsw(n+1);
  for(int i=1;i<=n;i++){
    rsw[i]+=rsw[i-1]+a[i];
  }
  long long ans=0;
  for(int i=1;i<=n;i++){
    ans+=rsw[n]-rsw[i]-(n-i)*a[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}