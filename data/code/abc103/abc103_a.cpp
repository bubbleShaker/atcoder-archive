#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  std::vector<int> a(3);
  for(int i=0;i<3;i++){
    std::cin>>a[i];
  }
  std::sort(a.begin(),a.end());
  std::cout<<std::min(a[2]-a[0],-(a[0]-a[2]))<<'\n';
  return 0;
}