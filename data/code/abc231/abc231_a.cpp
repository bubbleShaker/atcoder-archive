#include <iostream>
#include <iomanip>
int main(){
  double d;
  std::cin>>d;
  // #include<iomanip>
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<d/100<<'\n';
  return 0;
}