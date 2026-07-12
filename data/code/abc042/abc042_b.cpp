#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
int main(){
  int n,l;
  std::cin>>n>>l;
  std::vector<std::string> s(n);
  for(int i=0;i<n;i++){
    std::cin>>s[i];
  }
  std::sort(s.begin(),s.end());
  std::string ans;
  for(int i=0;i<n;i++){
    ans+=s[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}