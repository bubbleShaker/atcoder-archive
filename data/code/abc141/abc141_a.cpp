#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  if(s=="Sunny"){
    std::cout<<"Cloudy"<<'\n';
  }else if(s=="Cloudy"){
    std::cout<<"Rainy"<<'\n';
  }else{
    std::cout<<"Sunny"<<'\n';
  }
  return 0;
}