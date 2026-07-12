#include <iostream>
int main(){
  int a,b;
  std::cin>>a>>b;
  if(a+b==15){
    std::cout<<'+'<<'\n';
  }else if(a*b==15){
    std::cout<<'*'<<'\n';
  }else{
    std::cout<<'x'<<'\n';
  }
  return 0;
}