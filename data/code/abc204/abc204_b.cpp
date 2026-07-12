#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    ans+=((a>10)?a-10:0);
  }
  std::cout<<ans<<'\n';
  return 0;
}