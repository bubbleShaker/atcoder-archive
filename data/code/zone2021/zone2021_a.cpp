#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::string base="ZONe";
  int ans=0;
  for(int i=0;i<=s.size()-base.size();i++){
    if(s.substr(i,base.size())==base){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}