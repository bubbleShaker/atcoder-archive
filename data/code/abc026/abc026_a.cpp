#include <iostream>
#include <algorithm>
int main(){
  int a;
  std::cin>>a;
  int ans=0;
  for(int x=1;x<=a-1;x++){
    int y=a-x;
    ans=std::max(ans,x*y);
  }
  std::cout<<ans<<'\n';
  return 0;
}