#include <iostream>
#include <set>
int main(){
  int n,a,b,k;
  std::cin>>n>>a>>b>>k;
  std::set<int> visited_set;
  visited_set.insert(a);
  visited_set.insert(b);
  for(int i=0;i<k;i++){
    int p;
    std::cin>>p;
    if(visited_set.count(p)){
      std::cout<<"NO"<<'\n';
      return 0;
    }
    visited_set.insert(p);
  }
  std::cout<<"YES"<<'\n';
  return 0;
}