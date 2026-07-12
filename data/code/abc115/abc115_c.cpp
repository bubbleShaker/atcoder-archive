#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  const int INF=2e9;
  int n,k;
  std::cin>>n>>k;
  std::vector<int> h(n);
  for(int i=0;i<n;i++){
    std::cin>>h[i];
  }
  std::sort(h.begin(),h.end());
  int min_diff=INF;
  for(int i=0;i+k-1<n;i++){
    min_diff=std::min(min_diff,h[i+k-1]-h[i]);
  }
  std::cout<<min_diff<<'\n';
  return 0;
}