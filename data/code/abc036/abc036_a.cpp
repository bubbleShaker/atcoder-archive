#include <iostream>
int main(){
  int a,b;
  std::cin>>a>>b;
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  std::cout<<ceili(b,a)<<'\n';
  return 0;
}