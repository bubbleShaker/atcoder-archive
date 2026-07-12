#include <iostream>
#include <cmath>
int main(){
  double x,y,z;
  std::cin>>x>>y>>z;
  std::cout<<std::floor((z*y)/x)-(((int)z*(int)y%(int)x==0)?1:0)<<'\n';
  return 0;
}