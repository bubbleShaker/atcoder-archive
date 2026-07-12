#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  std::cin>>s;
  std::sort(s.begin(),s.end());
  std::cout<<s<<'\n';
  return 0;
}