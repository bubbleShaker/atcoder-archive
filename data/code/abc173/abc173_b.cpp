#include <iostream>
#include <map>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::string s;
  std::map<std::string,int> map;
  for(int i=0;i<n;i++){
    std::cin>>s;
    map[s]++;
  }
  std::cout<<"AC x "<<map["AC"]<<'\n';
  std::cout<<"WA x "<<map["WA"]<<'\n';
  std::cout<<"TLE x "<<map["TLE"]<<'\n';
  std::cout<<"RE x "<<map["RE"]<<'\n';
  return 0;
}