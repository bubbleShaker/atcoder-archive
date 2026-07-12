#include <iostream>
int main(){
  int n;
  std::cin>>n;
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  std::cout<<ceili(n,2)<<'\n';
  return 0;
}