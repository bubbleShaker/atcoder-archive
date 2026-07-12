#include <iostream>
#include <vector>
#include <bitset>
#include <atcoder/modint>
int main(){
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  auto ceilll=[&](long long a,long long b){
    return (a+(b-1))/b;
  };
  long long n,m;
  std::cin>>n>>m;
  std::bitset<61> bitset(m);
  const long long MOD=998244353;
  atcoder::modint::set_mod(MOD);
  auto sum_of_bit_under_M=[&](long long M){ //x<=Mのxの各ビットの総和を考える
    std::vector<long long> ret(61); //60ビット分のビットの1の和を考える
    for(int k=0;k<=60;k++){
      long long cnt=0;
      long long box_cnt=ceilll((n+1),powll(2,k+1));
      cnt+=(box_cnt-1)*powll(2,k); //確定で存在
      long long rem=n+1-((box_cnt-1)*powll(2,k+1));
      cnt+=std::max(0LL,rem-powll(2,k));
      ret[k]=cnt;
    }
    return ret;
  };
  std::vector<long long> bit_cnt=sum_of_bit_under_M(n);
  atcoder::modint ans=0;
  for(int k=0;k<=60;k++){
    if(bitset[k]){
      ans+=(atcoder::modint)bit_cnt[k];
    }
  }
  std::cout<<ans.val()<<'\n';
  return 0;
}