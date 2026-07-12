#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
int main(){
  int k,n;
  std::cin>>k>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::vector<int> diff;
  for(int i=0;i<n;i++){
    if(i==0){
      diff.push_back(k-a[n-1]+a[0]);
    }else{
      diff.push_back(std::abs(a[i]-a[i-1]));
    }
  }
  std::sort(diff.rbegin(),diff.rend());
  int ans=std::accumulate(diff.begin(),diff.end(),0);
  std::cout<<ans-diff[0]<<'\n';
  return 0;
}