#include <iostream>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<int> set;
  for(int i=1;i<=2*n+1;i++){
    set.insert(i);
  }
  while(1){
    std::cout<<*set.begin()<<'\n';
    std::cout<<std::flush;
    set.erase(*set.begin());
    int val;
    std::cin>>val;
    if(val==0){
      break;
    }else{
      set.erase(val);
    }
  }
  return 0;
}