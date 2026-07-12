#include <iostream>
#include <numeric>
int main(){
  long long a,b;
  std::cin>>a>>b;
  std::cout<<std::lcm(a,b)<<'\n';
  return 0;
}