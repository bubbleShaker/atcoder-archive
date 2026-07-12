#include <iostream>
#include <string>
int main(){
  std::string a,b;
  std::cin>>a>>b;
  // a+=b;
  std::cout<<std::stoi(a+b)*2<<'\n';
  return 0;
}