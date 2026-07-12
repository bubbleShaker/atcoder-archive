#include <iostream>
#include <algorithm>
#include <string>
int main(){
  long long k;
  std::cin>>k;
  auto to_bins=[&](long long val){
    std::string ret;
    while(val>0){
      ret+=std::to_string(val%2);
      val/=2;
    }
    std::reverse(ret.begin(),ret.end());
    return ret;
  }; 
  std::string ans=to_bins(k);
  for(int i=0;i<ans.size();i++){
    if(ans[i]=='1'){
      ans[i]='2';
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}