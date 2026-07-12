#include <iostream>
#include <algorithm>
int main(){
  int a,b,c,d,e;
  std::cin>>a>>b>>c>>d>>e;
  std::cout<<std::max(a+d+e,b+c+e)<<'\n';
  return 0;
}