#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::pair<int,int>> vec(n);
  for(int i=0;i<n;i++){
    std::cin>>vec[i].first;
    vec[i].second=i;
  }
  std::sort(vec.rbegin(),vec.rend());
  std::cout<<vec[1].second+1<<'\n';
  return 0;
}