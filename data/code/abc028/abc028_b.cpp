#include <iostream>
#include <string>
#include <map>
int main(){
  std::string s;
  std::cin>>s;
  std::map<char,int> map;
  for(int i=0;i<s.size();i++){
    map[s[i]]++;
  }
  std::cout<<map['A']<<' ';
  std::cout<<map['B']<<' ';
  std::cout<<map['C']<<' ';
  std::cout<<map['D']<<' ';
  std::cout<<map['E']<<' ';
  std::cout<<map['F']<<'\n';
  return 0;
}