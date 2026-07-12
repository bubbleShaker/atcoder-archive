#include <iostream>
#include <algorithm>
int main(){
  int n,x;
  std::cin>>n>>x;
  std::cout<<std::min(x-1,n-x)<<'\n';
  return 0;
}