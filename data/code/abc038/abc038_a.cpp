#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::cout<<((*(s.end()-1)=='T')?"YES":"NO")<<'\n';
  return 0;
}