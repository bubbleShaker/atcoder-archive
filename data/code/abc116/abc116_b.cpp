#include <iostream>
#include <set>
int main(){
  int s;
  std::cin>>s;
  std::set<int> set;
  int now=s;
  set.insert(now);
  for(int i=2;;i++){
    if(now%2==0){
      now/=2;
    }else{
      now=3*now+1;
    }
    if(set.count(now)){
      std::cout<<i<<'\n';
      return 0;
    }else{
      set.insert(now);
    }
  }
  return 0;
}