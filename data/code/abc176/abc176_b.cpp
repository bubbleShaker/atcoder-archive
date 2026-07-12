#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int sum=0;
  for(int i=0;i<s.size();i++){
    sum+=s[i]-'0';
  }
  if(sum%9==0){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}