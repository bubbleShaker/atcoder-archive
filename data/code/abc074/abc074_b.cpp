#include <iostream>
int main(){
  int n,k;
  std::cin>>n>>k;
  int ans=0;
  for(int i=0;i<n;i++){
    int x;
    std::cin>>x;
    ans+=2*std::min(x,k-x);
  }
  std::cout<<ans<<'\n';
  return 0;
}