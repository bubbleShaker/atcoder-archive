#include <iostream>
#include <algorithm>
#include <atcoder/modint>
using mint=atcoder::modint1000000007;
int main(){
  long long n;
  std::cin>>n;
  std::cout<<(mint(10).pow(n)-(mint(9).pow(n)+mint(9).pow(n)-mint(8).pow(n))).val()<<'\n';
  return 0;
}