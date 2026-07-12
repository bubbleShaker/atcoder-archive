#include <iostream>
#include <string>
#include <algorithm>
int main(){
  std::string s;
  int n;
  std::cin>>s>>n;
  for(int i=0;i<n;i++){
    int l,r;
    std::cin>>l>>r;
    l--;
    r--;
    std::reverse(s.begin()+l,s.begin()+r+1);
  }
  std::cout<<s<<'\n';
  return 0;
}