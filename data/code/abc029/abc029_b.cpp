#include <iostream>
#include <string>
int main(){
  int ans=0;
  for(int i=0;i<12;i++){
    std::string s;
    std::cin>>s;
    for(int j=0;j<s.size();j++){
      if(s[j]=='r'){
        ans++;
        break;
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}