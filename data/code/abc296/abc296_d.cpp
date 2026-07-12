#include <iostream>
int main(){
  const long long INF=4e18;
  long long n,m;
  std::cin>>n>>m;
  auto ceilll=[&](long long a,long long b){
    return (a+(b-1))/b;
  };
  long long ans=INF;
  for(long long a=1;a<=(long long)1e7;a++){
    long long b=ceilll(m,a);
    if(a<=n&&b<=n){
      ans=std::min(ans,a*b);
    }
  }
  if(ans==INF){
    std::cout<<-1<<'\n';
  }else{
    std::cout<<ans<<'\n';
  }
  return 0;
}