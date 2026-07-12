#include <iostream>
#include <numeric>
int main(){
  int n;
  std::cin>>n;
  long long ans=1;
  for(int i=0;i<n;i++){
    long long t;
    std::cin>>t;
    ans=std::lcm(ans,t);
  }
  std::cout<<ans<<'\n';
  return 0;
}