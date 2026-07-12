#include <iostream>
#include <string>
#include <set>
int main(){
  std::string s;
  int k;
  std::cin>>s>>k;
  if(s.size()<k){
    std::cout<<0<<'\n';
    return 0;
  }
  std::set<std::string> set;
  for(int i=0;i<=s.size()-k;i++){
    set.insert(s.substr(i,k));
  }
  std::cout<<set.size()<<'\n';
  return 0;
}