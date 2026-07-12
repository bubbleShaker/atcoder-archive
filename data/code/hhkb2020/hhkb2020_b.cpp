#include <iostream>
#include <vector>
#include <string>
int main(){
  int h,w;
  std::cin>>h>>w;
  std::vector<std::string> s(h);
  for(int i=0;i<h;i++){
    std::cin>>s[i];
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(j+1<w&&s[i][j]=='.'&&s[i][j+1]=='.'){
        ans++;
      }
      if(i+1<h&&s[i][j]=='.'&&s[i+1][j]=='.'){
        ans++;
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}