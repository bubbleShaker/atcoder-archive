#include <iostream>
#include <algorithm>
#include <string>
int main(){
  int r,g,b;
  std::string c;
  std::cin>>r>>g>>b>>c;
  if(c=="Red"){
    std::cout<<std::min(g,b)<<'\n';
  }else if(c=="Green"){
    std::cout<<std::min(r,b)<<'\n';
  }else if(c=="Blue"){
    std::cout<<std::min(r,g)<<'\n';
  }
  return 0;
}