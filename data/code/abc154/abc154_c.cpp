#include <iostream>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<int> set;
  bool is_ok=true;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    if(set.count(a)){
      is_ok=false;
    }
    set.insert(a);
  }
  if(is_ok){
    std::cout<<"YES"<<'\n';
  }else{
    std::cout<<"NO"<<'\n';
  }
  return 0;
}