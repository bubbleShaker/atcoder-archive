#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> t(n);
  for(int i=0;i<n;i++){
    std::cin>>t[i];
  }
  auto min=*std::min_element(t.begin(),t.end());
  std::cout<<min<<'\n';
  return 0;
}