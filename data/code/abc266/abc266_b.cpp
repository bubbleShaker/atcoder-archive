#include <iostream>
int main(){
  const long long MOD=998244353;
  long long n;
  std::cin>>n;
  if(n>0){
    std::cout<<n%MOD<<'\n';
  }else if(n<0){
    n*=-1;
    if(n%MOD==0){
      std::cout<<0<<'\n';
    }else{
      std::cout<<MOD-(n%MOD)<<'\n';
    }
  }else if(n==0){
    std::cout<<0<<'\n';
  }
  return 0;
}