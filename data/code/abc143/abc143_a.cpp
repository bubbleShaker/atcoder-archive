#include <iostream>
int main(){
  int a,b;
  std::cin>>a>>b;
  if(a<=2*b){
    std::cout<<0<<'\n';
  }else{
    std::cout<<a-2*b<<'\n';
  }
  return 0;
}