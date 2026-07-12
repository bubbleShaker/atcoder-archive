#include <iostream>
#include <vector>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  std::multiset<int> set;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    set.insert(a[i]);
  }
  for(int i=0;i<n;i++){
    set.erase(set.find(a[i]));
    std::cout<<*set.rbegin()<<'\n';
    set.insert(a[i]);
  }
  return 0;
}