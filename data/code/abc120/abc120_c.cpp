#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  std::cin>>s;
  int red_cnt=0;
  int blue_cnt=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='0'){
      red_cnt++;
    }else{
      blue_cnt++;
    }
  }
  std::cout<<std::min(red_cnt,blue_cnt)*2<<'\n';
  return 0;
}