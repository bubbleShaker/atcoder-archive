#include <iostream>
#include <string>
int main(){
  int n;
  std::cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    std::string s;
    std::cin>>s;
    if(s=="Takahashi"){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}