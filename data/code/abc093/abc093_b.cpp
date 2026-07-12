#include <iostream>
#include <set>
int main(){
  int a,b,k;
  std::cin>>a>>b>>k;
  std::set<int> set;
  for(int i=0;i<k;i++){
    if(a+i<=b){
      set.insert(a+i);
    }
    if(b-i>=a){
      set.insert(b-i);
    }
  }
  for(int ret:set){
    std::cout<<ret<<'\n';
  }
  return 0;
}