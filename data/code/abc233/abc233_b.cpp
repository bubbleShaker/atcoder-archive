#include <iostream>
#include <string>
#include <algorithm>
int main(){
  int l,r;
  std::cin>>l>>r;
  std::string s;
  std::cin>>s;
  std::reverse(s.begin()+l-1,s.begin()+r);
  std::cout<<s<<'\n';
  return 0;
}