#include <iostream>
int main(){
  int x,a,b;
  std::cin>>x>>a>>b;
  int cnt=(x-a)/b;
  std::cout<<x-(a+b*cnt)<<'\n';
  return 0;
}