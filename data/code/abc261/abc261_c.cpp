#include <iostream>
#include <string>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::map<std::string,int> map;
  for(int i=0;i<n;i++){
    std::string s;
    std::cin>>s;
    if(map[s]==0){
      std::cout<<s<<'\n';
    }else{
      std::cout<<s<<"("<<map[s]<<")"<<'\n';
    }
    map[s]++;
  }
  return 0;
}