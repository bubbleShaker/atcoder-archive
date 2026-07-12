#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  std::cin>>s;
  int n=s.size();
  for(int i=0;i<n;i++){
    std::string ss=s;
    std::reverse(ss.begin(),ss.end());
    if(s==ss){
      std::cout<<"Yes"<<'\n';
      return 0;
    }else{
      s="0"+s;
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}