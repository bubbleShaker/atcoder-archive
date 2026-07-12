#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::string ans;
  for(int i=0;i<s.size();i++){
    if(i%2==0){
      ans+=s[i];
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}