#include <iostream>
#include <string>
#include <set>
int main(){
  std::string s;
  std::cin>>s;
  std::set<char> set;
  for(int i=0;i<3;i++){
    set.insert(s[i]);
  }
  if(set.size()==1){
    std::cout<<1<<'\n';
  }else if(set.size()==2){
    std::cout<<3<<'\n';
  }else{
    std::cout<<6<<'\n';
  }
  return 0;
}