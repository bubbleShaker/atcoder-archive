#include <iostream>
#include <atcoder/modint>
int main(){
  const long long MOD=998244353;
  atcoder::modint::set_mod(MOD);
  long long n;
  std::cin>>n;
  auto keta=[&](long long val){
    int ret=0;
    while(val>0){
      val/=10;
      ret++;
    }
    return ret;
  };
  atcoder::modint ten=10;
  long long k=keta(n); //nの桁数
  atcoder::modint kousa=ten.pow(k); //公差は10^k
  atcoder::modint a=(atcoder::modint)n*(1-kousa.pow(n)); //項数はn
  atcoder::modint b=1-ten.pow(k); //分子用にinvをとる数
  atcoder::modint ans=a*b.inv(); //MODにおける逆元を計算
  std::cout<<ans.val()<<'\n';
  return 0;
}