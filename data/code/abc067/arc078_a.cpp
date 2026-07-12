#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
int main(){
  const long long INF=4e18;
  long long n;
  std::cin>>n;
  std::vector<int> a(n);
  long long left_rsw=0,right_rsw=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    right_rsw+=a[i];
  }
  long long min=INF;
  for(int i=0;i<n-1;i++){
    left_rsw+=a[i];
    right_rsw-=a[i];
    min=std::min(min,std::abs(left_rsw-right_rsw));
  }
  std::cout<<min<<'\n';
  return 0;
}