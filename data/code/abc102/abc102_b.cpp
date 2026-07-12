#include <iostream>
#include <algorithm>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  int min=INF;
  int max=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    max=std::max(max,a);
    min=std::min(min,a);
  }
  std::cout<<max-min<<'\n';
  return 0;
}