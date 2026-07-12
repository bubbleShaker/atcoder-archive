#include <iostream>
#include <cctype>
int main(){
  char s,t;
  std::cin>>s>>t;
  if(s=='Y'){
    std::cout<<char(std::toupper(t))<<'\n';
  }else{
    std::cout<<t<<'\n';
  }
  return 0;
}