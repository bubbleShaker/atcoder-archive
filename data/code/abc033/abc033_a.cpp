#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  std::cin>>s;
  if(all_of(s.begin(),s.end(),[&](char val){ return val==s[0]; })){
    std::cout<<"SAME"<<'\n';
  }else{
    std::cout<<"DIFFERENT"<<'\n';
  }
  return 0;
}