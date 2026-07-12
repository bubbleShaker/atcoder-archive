#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::string base="oxxoxxoxxoxx";
  for(int i=0;i<3;i++){
    if(base.substr(i,s.size())==s){
      std::cout<<"Yes"<<'\n';
      return 0;
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}