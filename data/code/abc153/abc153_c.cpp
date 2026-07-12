#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::vector<long long> h(n);
  for(int i=0;i<n;i++){
    std::cin>>h[i];
  }
  std::sort(h.rbegin(),h.rend());
  long long ans=std::accumulate(h.begin(),h.end(),0LL);
  for(int i=0;i<std::min(n,k);i++){
    ans-=h[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}