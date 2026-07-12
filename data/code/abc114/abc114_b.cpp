#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
int main(){
  const int INF=2e9;
  std::string s;
  std::cin>>s;
  int min=INF;
  for(int i=0;i<s.size()-2;i++){
    std::string ss=s.substr(i,3);
    int val=std::stoi(ss);
    min=std::min(min,std::abs(753-val));
  }
  std::cout<<min<<'\n';
  return 0;
}