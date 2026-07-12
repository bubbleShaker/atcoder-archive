#include <iostream>
int main(){
  int n,x,t;
  std::cin>>n>>x>>t;
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  std::cout<<ceili(n,x)*t<<'\n';
  return 0;
}