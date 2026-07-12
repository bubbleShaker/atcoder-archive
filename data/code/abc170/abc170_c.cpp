#include <iostream>
#include <set>
int main(){
  int x,n;
  std::cin>>x>>n;
  std::set<int> set;
  for(int i=0;i<n;i++){
    int p;
    std::cin>>p;
    set.insert(p);
  }
  for(int diff=0;;diff++){
    if(!set.count(x-diff)){
      std::cout<<x-diff<<'\n';
      return 0;
    }
    if(!set.count(x+diff)){
      std::cout<<x+diff<<'\n';
      return 0;
    }
  }
  return 0;
}