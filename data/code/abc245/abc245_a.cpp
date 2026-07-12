#include <iostream>
int main(){
  int a,b,c,d;
  std::cin>>a>>b>>c>>d;
  if(a<c){
    std::cout<<"Takahashi"<<'\n';
  }else if(a>c){
    std::cout<<"Aoki"<<'\n';
  }else if(a==c){
    if(b<=d){
      std::cout<<"Takahashi"<<'\n';
    }else{
      std::cout<<"Aoki"<<'\n';
    }
  }
  return 0;
}