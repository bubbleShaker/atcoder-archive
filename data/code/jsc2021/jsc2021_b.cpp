#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::set<int> set;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    set.insert(a);
  }
  for(int i=0;i<m;i++){
    int b;
    std::cin>>b;
    if(set.count(b)){
      set.erase(b);
    }else{
      set.insert(b);
    }
  }
  for(auto val:set){
    std::cout<<val<<" ";
  }
  return 0;
}