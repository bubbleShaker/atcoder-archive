#include <iostream>
#include <algorithm>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::cout<<s.substr(0,(std::find(s.begin(),s.end(),'.')-s.begin()))<<'\n';
  return 0;
}