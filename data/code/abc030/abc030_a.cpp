#include <iostream>
int main(){
  double a,b,c,d;
  std::cin>>a>>b>>c>>d;
  if(b/a>d/c){
    std::cout<<"TAKAHASHI"<<'\n';
  }else if(b/a<d/c){
    std::cout<<"AOKI"<<'\n';
  }else{
    std::cout<<"DRAW"<<'\n';
  }
  return 0;
}