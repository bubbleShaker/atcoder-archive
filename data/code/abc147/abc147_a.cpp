#include <iostream>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  if(a+b+c>=22){
    std::cout<<"bust"<<'\n';
  }else{
    std::cout<<"win"<<'\n';
  }
  return 0;
}