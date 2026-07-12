#include <iostream>
#include <iomanip>
#include <ios>
int main(){
  double a,b;
  std::cin>>a>>b;
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<(a*b)/100<<'\n';
  return 0;
}