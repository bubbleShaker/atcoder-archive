#include <iostream>
#include <iomanip>
int main(){
  double l;
  std::cin>>l;
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<(l/3)*(l/3)*(l/3)<<'\n';
  return 0;
}