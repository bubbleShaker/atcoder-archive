#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  if(s[0]=='R'){
    if(s[1]=='R'){
      if(s[2]=='R'){
        std::cout<<3<<'\n';
      }else{
        std::cout<<2<<'\n';
      }
    }else{
      std::cout<<1<<'\n';
    }
  }else if(s[1]=='R'){
    if(s[2]=='R'){
      std::cout<<2<<'\n';
    }else{
      std::cout<<1<<'\n';
    }
  }else if(s[2]=='R'){
    std::cout<<1<<'\n';
  }else{
    std::cout<<0<<'\n';
  }
  return 0;
}