#include <iostream>
#include <string>
int main(){
  std::string a,b;
  std::cin>>a>>b;
  std::cout<<((a.size()>b.size())?a:b)<<'\n';
  return 0;
}