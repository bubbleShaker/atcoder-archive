#include <iostream>
#include <string>
#include <cctype>
int main(){
  int a,b;
  std::cin>>a>>b;
  std::string s;
  std::cin>>s;
  for(int i=0;i<s.size();i++){
    if(i==a){
      if(s[i]!='-'){
        std::cout<<"No"<<'\n';
        return 0;
      }
    }else{
      if(std::isdigit(s[i])==false){
        std::cout<<"No"<<'\n';
        return 0;
      }
    }
  }
  std::cout<<"Yes"<<'\n';
  return 0;
}