#include <iostream>
#include <bitset>
#include <vector>
int main(){
  const long long MOD=1e9+7;
  int n;
  std::cin>>n;
  std::vector<long long> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  long long ans=0;
  for(int k=0;k<=60;k++){
    long long zero=0,one=0;
    for(int i=0;i<n;i++){
      std::bitset<60> bitset(a[i]);
      int b=bitset[k];
      if(b==0){
        zero++;
      }else if(b==1){
        one++;
      }
    }
    ans+=(((one*zero)%MOD)*(powll(2,k)%MOD))%MOD;
    ans%=MOD;
  }
  std::cout<<ans<<'\n';
  return 0;
}