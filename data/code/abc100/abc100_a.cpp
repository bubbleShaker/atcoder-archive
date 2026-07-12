#include <iostream>
int main(){
  int a,b;
  std::cin>>a>>b;
  std::cout<<((a<=8&&b<=8)?"Yay!":":(")<<'\n';
  return 0;
}