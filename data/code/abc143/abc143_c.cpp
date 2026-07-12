#include <iostream>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::string s;
  std::cin>>s;
  std::string ret;
  for(int i=0;i<n;i++){
    if(i==0){
      ret+=s[i];
    }else{
      if(ret[ret.size()-1]!=s[i]){
        ret+=s[i];
      }
    }
  }
  std::cout<<ret.size()<<'\n';
  return 0;
}