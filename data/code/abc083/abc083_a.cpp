#include <iostream>
int main(){
  int a,b,c,d;
  std::cin>>a>>b>>c>>d;
  if(a+b>c+d){
    std::cout<<"Left"<<'\n';
  }else if(a+b<c+d){
    std::cout<<"Right"<<'\n';
  }else{
    std::cout<<"Balanced"<<'\n';
  }
  return 0;
}