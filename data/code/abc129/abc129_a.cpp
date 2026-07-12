#include <iostream>
#include <algorithm>
int main(){
  int n,m,k;
  std::cin>>n>>m>>k;
  std::cout<<std::min({n+m,m+k,k+n})<<'\n';
  return 0;
}