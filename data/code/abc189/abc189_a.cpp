#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  if(s[0]==s[1]&&s[0]==s[2]&&s[1]==s[2]){
    std::cout<<"Won "<<'\n';
  }else{
    std::cout<<"Lost "<<'\n';
  }
  return 0;
}