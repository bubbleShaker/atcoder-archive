#include <iostream>
#include <algorithm>
#include<iomanip>
int main(){
  double sx,sy,gx,gy;
  std::cin>>sx>>sy>>gx>>gy;
  gy=-gy;
  double dx=std::abs(gx-sx);
  double dy=std::abs(gy-sy);
  std::cout<<std::fixed<<std::setprecision(10);
  double ans=((gx-sx>0)?sx+(dx*sy)/dy:sx-(dx*sy)/dy);
  std::cout<<ans<<'\n';
  return 0;
}