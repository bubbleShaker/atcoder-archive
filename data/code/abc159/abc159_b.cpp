#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  std::cin>>s;
  std::string ss=s;
  int n=s.size();
  std::reverse(ss.begin(),ss.end());
  
  if(s!=ss){
    std::cout<<"No"<<'\n';
    return 0;
  }
  
  std::string sb1=s.substr(0,(n-1)/2);
  std::string ssb1=sb1;
  std::reverse(ssb1.begin(),ssb1.end());
  if(sb1!=ssb1){
    std::cout<<"No"<<'\n';
    return 0;
  }
  
  std::string sb2=s.substr((n+3)/2-1);
  std::string ssb2=sb2;
  std::reverse(ssb2.begin(),ssb2.end());
  if(sb2!=ssb2){
    std::cout<<"No"<<'\n';
    return 0;
  }
  
  std::cout<<"Yes"<<'\n';
  
  return 0;
}