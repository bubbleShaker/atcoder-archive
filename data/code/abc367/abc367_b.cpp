#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  while(s[s.size()-1]=='0'){
    s.pop_back();
  }
  if(s[s.size()-1]=='.'){
    s.pop_back();
  }
  std::cout<<s<<'\n';
  return 0;
}