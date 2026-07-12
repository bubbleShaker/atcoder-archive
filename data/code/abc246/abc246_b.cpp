#include <iostream>
#include <cmath>
#include<iomanip>
int main(){
  double a,b;
  std::cin>>a>>b;
  double dist=std::sqrt(a*a+b*b);
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<a/dist<<" "<<b/dist<<'\n';
  return 0;
}