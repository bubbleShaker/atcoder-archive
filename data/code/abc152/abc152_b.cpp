#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string a,b;
  std::cin>>a>>b;
  std::string ret1,ret2;
  for(int i=0;i<std::stoi(b);i++){
    ret1+=a;
  }
  for(int i=0;i<std::stoi(a);i++){
    ret2+=b;
  }
  std::cout<<std::min(ret1,ret2)<<'\n';
  return 0;
}