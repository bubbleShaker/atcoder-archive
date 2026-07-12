#include <iostream>
int main(){
  int x,y;
  std::cin>>x>>y;
  if(x!=y){
    std::cout<<3-(x+y)<<'\n';
  }else{
    std::cout<<x<<'\n';
  }
  return 0;
}