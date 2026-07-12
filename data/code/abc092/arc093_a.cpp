#include <iostream>
#include <vector>
#include <cmath>
int main(){
  int n;
  std::cin>>n;
  std::vector<long long> a(n+2);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  long long base=0;
  for(int i=1;i<=n+1;i++){
    base+=std::abs(a[i]-a[i-1]);
  }
  long long ans=0;
  for(int i=1;i<=n;i++){
    std::cout<<base-(std::abs(a[i]-a[i-1])+std::abs(a[i+1]-a[i]))+std::abs(a[i-1]-a[i+1])<<'\n';
  }
  return 0;
}