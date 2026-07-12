#include <iostream>
int main(){
  int a,b,x;
  std::cin>>a>>b>>x;
  std::cout<<((a<=x&&x<=a+b)?"YES":"NO")<<'\n';
  return 0;
}