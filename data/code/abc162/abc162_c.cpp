#include <iostream>
#include <numeric>
int main(){
  int k;
  std::cin>>k;
  int ans=0;
  for(int a=1;a<=k;a++){
    for(int b=1;b<=k;b++){
      for(int c=1;c<=k;c++){
        ans+=std::gcd(std::gcd(a,b),c);
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}