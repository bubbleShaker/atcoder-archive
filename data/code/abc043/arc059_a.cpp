#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  int min=INF;
  for(int y=-100;y<=100;y++){
    int cost=0;
    for(int i=0;i<n;i++){
      cost+=(a[i]-y)*(a[i]-y);
    }
    min=std::min(min,cost);
  }
  std::cout<<min<<'\n';
  return 0;
}