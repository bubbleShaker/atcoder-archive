#include <iostream>
#include <string>
#include <algorithm>
int main(){
  int a,b;
  std::cin>>a>>b;
  int ans=0;
  for(int i=a;i<=b;i++){
    std::string s=std::to_string(i);
    std::string ss=std::to_string(i);
    std::reverse(ss.begin(),ss.end());
    if(s==ss){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}