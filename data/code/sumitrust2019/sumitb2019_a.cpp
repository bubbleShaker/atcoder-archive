#include <iostream>
int main(){
  int m1,d1,m2,d2;
  std::cin>>m1>>d1>>m2>>d2;
  if(m1!=m2){
    std::cout<<1<<'\n';
  }else{
    std::cout<<0<<'\n';
  }
  return 0;
}