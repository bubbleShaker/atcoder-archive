#include <iostream>
#include <algorithm>
#include <map>
int main(){
  int n;
  std::cin>>n;
  int max_1=0;
  int max_2=0;
  auto powi=[&](int a,int b){
    int ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  std::map<int,int> map;
  for(int i=1;i<=powi(2,n);i++){
    int a;
    std::cin>>a;
    map[a]=i;
    if(i<=powi(2,n)/2){
      max_1=std::max(max_1,a);
    }else{
      max_2=std::max(max_2,a);
    }
  }
  std::cout<<map[std::min(max_1,max_2)]<<'\n';
  return 0;
}