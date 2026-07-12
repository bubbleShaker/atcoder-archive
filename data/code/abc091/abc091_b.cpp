#include <iostream>
#include <string>
#include <algorithm>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::map<std::string,int> map;
  for(int i=0;i<n;i++){
    std::string s;
    std::cin>>s;
    map[s]++;
  }
  int m;
  std::cin>>m;
  for(int i=0;i<m;i++){
    std::string t;
    std::cin>>t;
    map[t]--;
  }
  int ans=0;
  for(auto [s,money]:map){
    ans=std::max(ans,money);
  }
  std::cout<<ans<<'\n';
  return 0;
}