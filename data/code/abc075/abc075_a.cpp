#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  std::vector<int> a(3);
  for(int i=0;i<3;i++){
    std::cin>>a[i];
  }
  sort(a.begin(),a.end());
  std::cout<<((a[0]==a[1])?a[2]:a[0])<<'\n';
  return 0;
}