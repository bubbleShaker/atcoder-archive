#include <iostream>
int main(){
  long long n,m;
  std::cin>>n>>m;
  long long ans=0;
  if(2*n<=m){
    ans+=n;
    m-=2*n;
    ans+=m/4;
  }else{
    ans=m/2;
  }
  std::cout<<ans<<'\n';
  return 0;
}