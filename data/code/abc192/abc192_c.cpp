#include <iostream>
#include <algorithm>
#include <string>
int main(){
  long long n,k;
  std::cin>>n>>k;
  auto g1=[&](long long x){
    std::string ret=std::to_string(x);
    std::sort(ret.rbegin(),ret.rend());
    return std::stoll(ret);
  };
  auto g2=[&](long long x){
    std::string ret=std::to_string(x);
    std::sort(ret.begin(),ret.end());
    return std::stoll(ret);
  };
  auto f=[&](long long x){
    return g1(x)-g2(x);
  };
  long long prev_a=n;
  // std::cout<<prev_a<<'\n';
  long long a=n;
  for(int i=1;i<=k;i++){
    a=f(prev_a);
    prev_a=a;
  }
  std::cout<<a<<'\n';
  return 0;
}