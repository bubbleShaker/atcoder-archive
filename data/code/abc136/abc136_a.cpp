#include <iostream>
#include <algorithm>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  int can=a-b;
  std::cout<<std::max(0,c-can)<<'\n';
  return 0;
}