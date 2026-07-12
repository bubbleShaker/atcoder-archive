#include <iostream>
#include <string>
#include <set>
int main(){
  std::string s;
  std::cin>>s;
  std::set<char> set;
  for(int i=0;i<s.size();i++){
    if(set.count(s[i])){
      std::cout<<"no"<<'\n';
      return 0;
    }else{
      set.insert(s[i]);
    }
  }
  std::cout<<"yes"<<'\n';
  return 0;
}