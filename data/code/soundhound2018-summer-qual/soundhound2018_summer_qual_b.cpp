#include <iostream>
#include <string>
int main(){
  std::string s;
  int w;
  std::cin>>s>>w;
  std::string ans;
  for(int i=0;i<s.size();i+=w){
    ans+=s[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}