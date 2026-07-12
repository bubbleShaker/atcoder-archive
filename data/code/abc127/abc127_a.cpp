#include <iostream>
int main(){
  int a,b;
  std::cin>>a>>b;
  if(a<=5){
    std::cout<<0<<'\n';
  }else if(a<=12){
    std::cout<<b/2<<'\n';
  }else{
    std::cout<<b<<'\n';
  }
  return 0;
}