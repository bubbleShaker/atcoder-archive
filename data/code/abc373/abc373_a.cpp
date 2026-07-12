#include <iostream>
#include <vector>
#include <string>
int main(){
  std::vector<std::string>  s(13);
  int ans=0;
  for(int i=1;i<=12;i++){
    std::cin>>s[i];
    if(s[i].size()==i){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}