#include <iostream>
#include <string>
#include <algorithm>
int main(){
  int n;
  std::string s;
  std::cin>>n>>s;
  int idx=std::find_if(s.begin(),s.end(),[&](char c){ return c=='1'; })-s.begin();
  std::cout<<((idx%2==0)?"Takahashi":"Aoki")<<'\n';
  return 0;
}