#include <iostream>
#include <string>
int main(){
  int n,k;
  std::string s;
  std::cin>>n>>s>>k;
  for(int i=0;i<s.size();i++){
    if(s[i]!=s[k-1]){
      s[i]='*';
    }
  }
  std::cout<<s<<'\n';
  return 0;
}