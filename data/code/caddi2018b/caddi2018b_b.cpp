#include <iostream>
int main(){
  int n,h,w;
  std::cin>>n>>h>>w;
  int ans=0;
  for(int i=0;i<n;i++){
    int a,b;
    std::cin>>a>>b;
    if(a>=h&&b>=w){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}