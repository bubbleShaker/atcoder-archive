#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int n1=std::stoi(s.substr(0,2));
  int n2=std::stoi(s.substr(2,2));
  if(1<=n1&&n1<=12&&1<=n2&&n2<=12){
    std::cout<<"AMBIGUOUS"<<'\n';
  }else if(1<=n1&&n1<=12){
    std::cout<<"MMYY"<<'\n';
  }else if(1<=n2&&n2<=12){
    std::cout<<"YYMM"<<'\n';
  }else{
    std::cout<<"NA"<<'\n';
  }
  return 0;
}