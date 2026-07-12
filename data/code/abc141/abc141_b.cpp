#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  for(int i=0;i<s.size();i++){
    if(i%2){
      if(s[i]=='L'||s[i]=='D'||s[i]=='U'){
        continue;
      }
      std::cout<<"No"<<'\n';
      return 0;
    }else{
      if(s[i]=='R'||s[i]=='D'||s[i]=='U'){
        continue;
      }
      std::cout<<"No"<<'\n';
      return 0;
    }
  }
  std::cout<<"Yes"<<'\n';
  return 0;
}