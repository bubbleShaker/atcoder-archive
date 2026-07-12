#include <iostream>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::string s,t;
  std::cin>>s>>t;
  std::string ans;
  for(int i=0;i<n;i++){
    ans+=s[i];
    ans+=t[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}