#include <iostream>
#include <algorithm>
#include <string>
int main(){
  std::string s;
  int k;
  std::cin>>s>>k;
  std::sort(s.begin(),s.end());
  int cnt=0;
  do{
    if(++cnt==k){
      std::cout<<s<<'\n';
      return 0;
    }
  }while(std::next_permutation(s.begin(),s.end()));
  return 0;
}