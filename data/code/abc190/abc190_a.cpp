#include <iostream>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  if(a==b){
    if(c==0){
      std::cout<<"Aoki"<<'\n';
    }else{
      std::cout<<"Takahashi"<<'\n';
    }
  }else if(a>b){
    std::cout<<"Takahashi"<<'\n';
  }else{
    std::cout<<"Aoki"<<'\n';
  }
  return 0;
}