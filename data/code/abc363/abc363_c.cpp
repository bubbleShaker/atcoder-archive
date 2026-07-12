#include <iostream>
#include <algorithm>
#include <string>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::string s;
  std::cin>>s;
  std::sort(s.begin(),s.end());
  long long ans=0;
  auto is_kaibun=[&](std::string ret){
    int n=ret.size();
    for(int i=0;i<n/2;i++){
      if(ret[i]!=ret[n-1-i]){
        return false;
      }
    }
    return true;
  };
  do{
    bool is_ok=true;
    for(int i=0;i<=n-k;i++){
      std::string ret=s.substr(i,k);
      if(is_kaibun(ret)){
        is_ok=false;
      }
    }
    if(is_ok){
      ans++;
    }
  }while(std::next_permutation(s.begin(),s.end()));
  std::cout<<ans<<'\n';
  return 0;
}