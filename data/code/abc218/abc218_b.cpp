#include <iostream>
#include <string>
#include <vector>
int main(){
  std::string base="abcdefghijklmnopqrstuvwxyz";
  std::string ans;
  for(int i=0;i<26;i++){
    int p;
    std::cin>>p;
    p--;
    ans+=base[p];
  }
  std::cout<<ans<<'\n';
  return 0;
}