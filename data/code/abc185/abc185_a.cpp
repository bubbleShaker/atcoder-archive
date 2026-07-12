#include <iostream>
#include <algorithm>
int main(){
  int n,m,k,l;
  std::cin>>n>>m>>k>>l;
  std::cout<<std::min({n,m,k,l})<<'\n';
  return 0;
}