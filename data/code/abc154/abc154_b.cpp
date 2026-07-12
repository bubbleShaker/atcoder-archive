#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  for(int i=0;i<s.size();i++){
    s[i]='x';
  }
  std::cout<<s<<'\n';
  return 0;
}