#include <iostream>
#include <string>
int main(){
  std::string a;
  std::cin>>a;
  std::cout<<((a!="a")?"a":"-1")<<'\n';
  return 0;
}