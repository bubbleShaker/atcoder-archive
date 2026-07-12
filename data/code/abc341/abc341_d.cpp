#include <iostream>
#include <algorithm>
#include <numeric>
int main(){
  const long long INF=4e18;
  long long n,m,k;
  std::cin>>n>>m>>k;
  auto is_ok=[&](long long x){
    long long y=x/std::lcm(n,m);
    return x/n+x/m-2*y>=k;
  };
  long long ok=INF;
  long long ng=0;
  while(abs(ok-ng)>1){
    // std::cout<<"ok is "<<ok<<'\n';
    long long mid=(ok+ng)/2;
    if(is_ok(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  if(ok%std::lcm(n,m)==0){
    ok=std::min(ok-n,ok-m);
  }
  std::cout<<ok<<'\n';
  return 0;
}