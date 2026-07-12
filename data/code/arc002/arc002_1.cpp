#include <iostream>
#include <chrono>
int main(){
  int y;
  std::cin>>y;
  if(std::chrono::year{y}.is_leap()){
    std::cout<<"YES"<<'\n';
  }else{
    std::cout<<"NO"<<'\n';
  }
  return 0;
}