#include <iostream>
#include <string>
#include <cctype>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::string s;
  std::cin>>s;
  s[k-1]=std::tolower(s[k-1]);
  std::cout<<s<<'\n';
  return 0;
}