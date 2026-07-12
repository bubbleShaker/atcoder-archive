#include <iostream>
#include <vector>
int main(){
  std::vector<int> s(3),e(3);
  int ans=0;
  for(int i=0;i<3;i++){
    std::cin>>s[i]>>e[i];
    ans+=s[i]/10*e[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}