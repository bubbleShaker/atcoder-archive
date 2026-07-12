#include <iostream>
#include <algorithm>
int main(){
  int n,m,x;
  std::cin>>n>>m>>x;
  int sum1=0,sum2=0;
  for(int i=0;i<m;i++){
    int a;
    std::cin>>a;
    if(a<x){
      sum1++;
    }else if(x<a){
      sum2++;
    }
  }
  std::cout<<std::min(sum1,sum2)<<'\n';
  return 0;
}