#include <iostream>
#include <cmath>
int main(){
  double n;
  std::cin>>n;
  int p=(int)std::floor(1.08*n);
  if(p<206){
    std::cout<<"Yay!"<<'\n';
  }else if(p==206){
    std::cout<<"so-so"<<'\n';
  }else{
    std::cout<<":("<<'\n';
  }
  return 0;
}