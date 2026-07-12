#include <iostream>
#include <cmath>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  if(a>=0&&b>=0){
    if(a==b){
      std::cout<<"="<<'\n';
    }else if(a<b){
      std::cout<<"<"<<'\n';
    }else if(a>b){
      std::cout<<">"<<'\n';
    }
  }else if(a<0&&b<0){
    if(a==b){
      std::cout<<"="<<'\n';
    }else if(a<b){
      if(c%2==0){
        std::cout<<">"<<'\n';
      }else{
        std::cout<<"<"<<'\n';
      }
    }else if(a>b){
      if(c%2==0){
        std::cout<<"<"<<'\n';
      }else{
        std::cout<<">"<<'\n';
      }
    }
  }else if(a>=0&&b<0){
    if(c%2==0){
      if(std::abs(a)==std::abs(b)){
        std::cout<<"="<<'\n';
      }else if(std::abs(a)<std::abs(b)){
        std::cout<<"<"<<'\n';
      }else{
        std::cout<<">"<<'\n';
      }
    }else{
      std::cout<<">"<<'\n';
    }
  }else if(a<0&&b>=0){
    if(c%2==0){
      if(std::abs(a)==std::abs(b)){
        std::cout<<"="<<'\n';
      }else if(std::abs(a)<std::abs(b)){
        std::cout<<"<"<<'\n';
      }else{
        std::cout<<">"<<'\n';
      }
    }else{
      std::cout<<"<"<<'\n';
    }
  }
  return 0;
}