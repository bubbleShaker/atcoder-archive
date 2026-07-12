#include <iostream>
#include <string>
int main(){
  std::string o,e;
  std::cin>>o>>e;
  std::string ans;
  for(int i=0;i<e.size();i++){
    ans+=o[i];
    ans+=e[i];
  }
  if(o.size()>e.size()){
    ans+=o[o.size()-1];
  }
  std::cout<<ans<<'\n';
  return 0;
}