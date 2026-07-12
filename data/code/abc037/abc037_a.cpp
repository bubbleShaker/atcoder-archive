#include <iostream>
#include <algorithm>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  std::cout<<c/std::min(a,b)<<'\n';
  return 0;
}