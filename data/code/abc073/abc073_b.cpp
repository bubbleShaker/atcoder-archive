#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    int l,r;
    std::cin>>l>>r;
    ans+=r-l+1;
  }
  std::cout<<ans<<'\n';
  return 0;
}