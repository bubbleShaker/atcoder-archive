#include <iostream>
#include <string>
int main(){
  int n;
  std::string s;
  std::cin>>n>>s;
  if(n%2){
    std::cout<<"No"<<'\n';
    return 0;
  }
  std::string s1=s.substr(0,n/2);
  std::string s2=s.substr(n/2);
  if(s1==s2){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}