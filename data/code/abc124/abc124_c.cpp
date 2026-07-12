#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  std::cin>>s;
  std::string case1,case2;
  for(int i=0;i<s.size();i++){
    if(i%2==0){
      case1+='0';
      case2+='1';
    }else{
      case1+='1';
      case2+='0';
    }
  }
  int diff1=0;
  int diff2=0;
  for(int i=0;i<s.size();i++){
    if(s[i]!=case1[i]){
      diff1++;
    }
    if(s[i]!=case2[i]){
      diff2++;
    }
  }
  std::cout<<std::min(diff1,diff2)<<'\n';
  return 0;
}