#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int n=s.size();
  int idx=0;
  while(idx!=n){
    if(s[idx]=='c'){
      if(idx+1>=n){
        std::cout<<"NO"<<'\n';
        return 0;
      }else{
        if(s[idx+1]=='h'){
          idx+=2;
        }else{
          std::cout<<"NO"<<'\n';
          return 0;
        }
      }
    }else if(s[idx]=='o'){
      idx++;
    }else if(s[idx]=='k'){
      idx++;
    }else if(s[idx]=='u'){
      idx++;
    }else{
      std::cout<<"NO"<<'\n';
      return 0;
    }
  }
  std::cout<<"YES"<<'\n';
  return 0;
}