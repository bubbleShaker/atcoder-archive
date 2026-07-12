#include <iostream>
#include <cmath>
int main(){
  double n;
  std::cin>>n;
  double a1=std::floor((n*100)/108);
  double a2=a1+1;
  if(std::floor(a1*1.08)==n){
    std::cout<<a1<<'\n';
  }else if(std::floor(a2*1.08)==n){
    std::cout<<a2<<'\n';
  }else{
    std::cout<<":("<<'\n';
  }
  return 0;
}