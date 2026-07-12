#include <iostream>
using namespace std;
int main(){
  int n;
  std::cin>>n;
  if(n<=125){
    std::cout<<4<<'\n';
  }else if(n<=211){
    std::cout<<6<<'\n';
  }else{
    std::cout<<8<<'\n';
  }
  return 0;
}