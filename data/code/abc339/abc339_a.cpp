#include <iostream>
#include <algorithm>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::string ans;
  for(int i=s.size()-1;i>=0;i--){
    if(s[i]=='.'){
      break;
    }else{
      ans+=s[i];
    }
  }
  std::reverse(ans.begin(),ans.end());
  std::cout<<ans<<'\n';
  return 0;
}