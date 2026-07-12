#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(){
  std::string s,t;
  std::cin>>s>>t;
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  for(int w=1;w<s.size();w++){
    std::string ss=s;
    std::vector<std::string> vec;
    int n=ceili(s.size(),w);
    for(int i=0;i<n;i++){
      vec.push_back(ss.substr(0,std::min((int)ss.size(),w)));
      ss=ss.substr(std::min((int)ss.size(),w));
    }
    for(int c=1;c<=w;c++){
      std::string ret;
      for(std::string str:vec){
        // if(w==2&&c==1){
        //   // std::cerr<<str<<'\n';
        // }
        if(str.size()<c){
          continue;
        }else{
          ret+=str[c-1];
        }
      }
      if(ret==t){
        std::cout<<"Yes"<<'\n';
        return 0;
      }
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}