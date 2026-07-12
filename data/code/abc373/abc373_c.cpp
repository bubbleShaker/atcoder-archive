#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<n;i++){
    std::cin>>b[i];
  }
  auto max_a=*std::max_element(a.begin(),a.end());
  auto max_b=*std::max_element(b.begin(),b.end());
  std::cout<<max_a+max_b<<'\n';
  return 0;
}