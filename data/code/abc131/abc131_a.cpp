#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  for(int i=0;i<3;i++){
    if(s[i]==s[i+1]){
      std::cout<<"Bad"<<'\n';
      return 0;
    }
  }
  std::cout<<"Good"<<'\n';
  return 0;
}