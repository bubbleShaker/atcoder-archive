#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
int main(){
  double n,m;
  std::cin>>n>>m;
  if(n>=12){
    n-=12;
  }
  double deg_h=360*(n/12)+30*(m/60);
  double deg_m=360*(m/60);
  double diff=std::abs(deg_h-deg_m);
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<std::min(diff,360-diff)<<'\n';
  return 0;
}