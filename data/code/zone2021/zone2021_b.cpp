#include <iostream>
#include <algorithm>
#include <iomanip>
int main(){
  double n,D,H;
  std::cin>>n>>D>>H;
  double ans=0;
  for(int i=0;i<n;i++){
    double d,h;
    std::cin>>d>>h;
    ans=std::max(ans,(d*H-D*h)/(d-D));
  }
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<ans<<'\n';
  return 0;
}