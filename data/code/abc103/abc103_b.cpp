#include <iostream>
#include <algorithm>
int main(){
  std::string s,t;
  std::cin>>s>>t;
  for(int i=0;i<s.size();i++){
    std::string ss=s;
    std::rotate(ss.begin(),ss.begin()+i,ss.end());
    if(ss==t){
      std::cout<<"Yes"<<'\n';
      return 0;
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}