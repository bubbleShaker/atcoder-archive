#include <iostream>
int main(){
  int n,h,w;
  std::cin>>n>>h>>w;
  std::cout<<(n-h+1)*(n-w+1)<<'\n';
  return 0;
}