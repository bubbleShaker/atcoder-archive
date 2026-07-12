#include <iostream>
#include <iomanip>
int main(){
  int n;
  std::cin>>n;
  std::cout<<"AGC";
  // include <iomanip>
  std::cout<<std::setw(3)<<std::setfill('0');
  std::cout<<((n>=42)?n+1:n)<<'\n';
  return 0;
}