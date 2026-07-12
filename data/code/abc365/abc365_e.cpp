#include <iostream>
#include <bitset>
#include <vector>
#include <numeric>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n+1);
  for(int i=1;i<=n;i++){
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
  for(int k=0;k<=30;k++){
    std::vector<int> b(n+1);//2進数でa[i]のk桁目が1ならb[i]=1
    for(int i=1;i<=n;i++){
      std::bitset<30> bitset(a[i]);
      b[i]=bitset[k];//k桁目が1ならb[i]=1
      // std::cout<<b[i]<<((i!=n)?' ':'\n');
    }
    int sum_b=std::accumulate(b.begin(),b.end(),0);//intなら0,long longなら0LLにすることに注意
    std::vector<int> c(n+1);//累積xor用
    long long zero=0,one=0;
    for(int i=1;i<=n;i++){
      c[i]=c[i-1]^b[i];
      // std::cout<<c[i]<<((i!=n)?' ':'\n');
    }
    for(int i=0;i<=n;i++){
      if(c[i]==0){
        zero++;
      }else if(c[i]==1){
        one++;
      }
    }
    ans+=(long long)(one*zero-sum_b)*powll(2,k);
  }
  std::cout<<ans<<'\n';
  return 0;
}