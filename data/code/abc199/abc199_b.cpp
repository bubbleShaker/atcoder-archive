#include <iostream>
#include <algorithm>
int main(){
  const int INF=1e9;
  int n;
  std::cin>>n;
  int max_a=0,min_b=INF;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    max_a=std::max(max_a,a);
  }
  for(int i=0;i<n;i++){
    int b;
    std::cin>>b;
    min_b=std::min(min_b,b);
  }
  std::cout<<std::max(0,min_b-max_a+1)<<'\n';
  return 0;
}