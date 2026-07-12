#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main(){
  std::vector<std::string> s(2);
  for(int i=0;i<2;i++){
    std::cin>>s[i];
  }
  std::vector<std::string> t=s;
  std::reverse(t.begin(),t.end());
  for(int i=0;i<2;i++){
    std::reverse(t[i].begin(),t[i].end());
  }
  std::cout<<((s==t)?"YES":"NO")<<'\n';
  return 0;
}