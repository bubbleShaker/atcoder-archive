#include <iostream>
#include <string>
#include <set>
int main(){
  std::string s;
  std::cin>>s;
  std::string ss="abcdefghijklmnopqrstuvwxyz";
  std::set<char> set(ss.begin(),ss.end());
  for(int i=0;i<s.size();i++){
    if(set.count(s[i])){
      set.erase(s[i]);
    }
  }
  if(set.size()!=0){
    std::cout<<*set.begin()<<'\n';
  }else{
    std::cout<<"None"<<'\n';
  }
  return 0;
}