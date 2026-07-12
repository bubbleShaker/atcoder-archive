#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  std::vector<int> a(3);
  for(int i=0;i<3;i++){
    std::cin>>a[i];
  }
  std::sort(a.rbegin(),a.rend());
  std::cout<<a[0]*10+a[1]+a[2]<<'\n';
  return 0;
}