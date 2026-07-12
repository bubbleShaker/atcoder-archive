#include <iostream>
#include <numbers>
#include <iomanip>
int main(){
  double PI=std::numbers::pi;
  double r;
  std::cin>>r;
  // #include<iomanip>
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<2*r*PI<<'\n';
  return 0;
}