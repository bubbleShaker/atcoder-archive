#include <iostream>
#include <algorithm>
#include <string>
int main(){
  int n;
  std::cin>>n;
  int ans=0;
  auto to_oct=[&](int val){
    std::string ret;
    while(val>0){
      ret+=std::to_string(val%8);
      val/=8;
    }
    std::reverse(ret.begin(),ret.end());
    return std::stoi(ret);
  };
  for(int i=1;i<=n;i++){
    int oct_i=to_oct(i);
    std::string i_s=std::to_string(i);
    std::string oct_i_s=std::to_string(oct_i);
    bool is_ok=true;
    for(int j=0;j<i_s.size();j++){
      if(i_s[j]-'0'==7){
        is_ok=false;
      }
    }
    for(int j=0;j<oct_i_s.size();j++){
      if(oct_i_s[j]-'0'==7){
        is_ok=false;
      }
    }
    if(is_ok){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}