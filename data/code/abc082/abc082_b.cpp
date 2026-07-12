#include <iostream>
#include <algorithm>
#include <string>
int main(){
  std::string s,t;
  std::cin>>s>>t;
  std::sort(s.begin(),s.end());
  std::sort(t.rbegin(),t.rend());
  if(s<t){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}