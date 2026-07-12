#include <iostream>
#include <algorithm>
int main(){
  const int INF=1e9;
  int ans=INF;
  int n;
  std::cin>>n;
  for(int i=0;i<n;i++){
    int a,p,x;
    std::cin>>a>>p>>x;
    if(a<x){
      ans=std::min(ans,p);
    }
  }
  std::cout<<((ans!=INF)?ans:-1)<<'\n';
  return 0;
}