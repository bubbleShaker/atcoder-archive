#include <iostream>
int main(){
  const long long MOD=1e9+7;
  long long n,m;
  std::cin>>n>>m;
  auto fact=[&](long long n){
    long long ret=1;
    while(n>0){
      ret*=n--;
      ret%=MOD;
    }
    return ret;
  };
  if(std::abs(n-m)>=2){
    std::cout<<0<<'\n';
  }else{
    std::cout<<(((n==m)?2:1)*((fact(n)*fact(m))))%MOD<<'\n';
  }
  return 0;
}