#include <iostream>
#include <algorithm>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  if(s.size()==2){
    std::cout<<s<<'\n';
  }else{
    std::reverse(s.begin(),s.end());
    std::cout<<s<<'\n';
  }
  return 0;
}