#include <iostream>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  int min=2000;
  int max=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    min=std::min(min,a);
    max=std::max(max,a);
  }
  std::cout<<max-min<<'\n';
  return 0;
}