#include <iostream>
#include <algorithm>
int main(){
  int n,x;
  std::cin>>n>>x;
  int min=2000;
  for(int i=0;i<n;i++){
    int m;
    std::cin>>m;
    min=std::min(min,m);
    x-=m;
  }
  std::cout<<n+x/min<<'\n';
  return 0;
}