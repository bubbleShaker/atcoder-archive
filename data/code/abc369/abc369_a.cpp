#include <iostream>
#include <cmath>
int main(){
  int a,b;
  std::cin>>a>>b;
  int diff=std::abs(a-b);
  if(diff==0){
    std::cout<<1<<'\n';
  }else if(diff%2==0){
    std::cout<<3<<'\n';
  }else if(diff%2){
    std::cout<<2<<'\n';
  }
  return 0;
}