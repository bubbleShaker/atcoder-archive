#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int p;
  std::cin>>p;
  auto fact=[&](int n){
    int ret=1;
    while(n>0){
      ret*=n--;
    }
    return ret;
  };
  std::vector<int> cnt(11,100);
  int ans=0;
  for(int i=10;i>=0;i--){
    if(p==0){
      break;
    }
    int c=p/fact(i);
    p-=std::min(100,c)*fact(i);
    ans+=std::min(100,c);
  }
  std::cout<<ans<<'\n';
  return 0;
}