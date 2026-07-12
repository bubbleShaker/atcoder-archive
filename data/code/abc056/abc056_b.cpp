#include <iostream>
#include <utility>
#include <algorithm>
int main(){
  int w,a,b;
  std::cin>>w>>a>>b;
  if(a>b){
    std::swap(a,b);
  }
  std::cout<<std::max(0,b-(a+w))<<'\n';
  return 0;
}