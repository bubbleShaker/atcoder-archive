#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<long long> a(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  std::vector<long long> rsw(n+1);
  std::vector<long long> max(n+1);
  for(int i=1;i<=n;i++){
    rsw[i]+=a[i]+rsw[i-1];
    max[i]=std::max(max[i-1],rsw[i]);
  }
  long long ans=0;
  long long cur=0;
  for(int i=1;i<=n;i++){
    ans=std::max(ans,cur+max[i]);
    cur+=rsw[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}