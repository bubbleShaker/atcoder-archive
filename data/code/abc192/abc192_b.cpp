#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  for(int i=0;i<s.size();i++){
    if(i%2==0){
      if(std::islower(s[i])==false){
        std::cout<<"No"<<'\n';
        return 0;
      }
    }else{
      if(std::isupper(s[i])==false){
        std::cout<<"No"<<'\n';
        return 0;
      }
    }
  }
  std::cout<<"Yes"<<'\n';
  return 0;
}