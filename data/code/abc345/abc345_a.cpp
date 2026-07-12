#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int n=s.size();
  if(s[0]=='<'&&s[n-1]=='>'){
    bool is_ok=true;
    for(int i=1;i<n-1;i++){
      if(s[i]!='='){
        is_ok=false;
        break;
      }
    }
    if(is_ok){
      std::cout<<"Yes"<<'\n';
      return 0;
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}