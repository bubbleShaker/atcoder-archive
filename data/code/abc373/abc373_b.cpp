#include <iostream>
#include <string>
#include <cmath>
#include <map>
int main(){
  std::string base="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string s;
  std::cin>>s;
  std::map<char,int> map;
  for(int i=0;i<s.size();i++){
    map[s[i]]=i;
  }
  int ans=0;
  for(int i=1;i<base.size();i++){
    ans+=std::abs(map[base[i]]-map[base[i-1]]);
  }
  std::cout<<ans<<'\n';
  return 0;
}