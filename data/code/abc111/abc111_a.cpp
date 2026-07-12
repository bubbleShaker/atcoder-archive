#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::string ans=s;
  for(int i=0;i<3;i++){
    if(s[i]=='1'){
      ans[i]='9';
    }else if(s[i]=='9'){
      ans[i]='1';
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}