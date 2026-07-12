#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::pair<int,int>> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i].first;
    a[i].second=i;
  }
  std::sort(a.rbegin(),a.rend());
  for(int i=0;i<n;i++){
    std::cout<<a[i].second+1<<'\n';
  }
  return 0;
}