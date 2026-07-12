#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  if(s=="abc"||s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba"){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}