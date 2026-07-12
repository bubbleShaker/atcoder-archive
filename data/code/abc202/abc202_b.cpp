#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  std::cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='6'){
      s[i]='9';
    }else if(s[i]=='9'){
      s[i]='6';
    }
  }
  std::reverse(s.begin(),s.end());
  std::cout<<s<<'\n';
  return 0;
}