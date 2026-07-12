#include <iostream>
int main(){
  long long n,T;
  std::cin>>n>>T;
  long long prev_t;
  long long ans=0;
  for(int i=0;i<n;i++){
    long long t;
    std::cin>>t;
    if(i==0){
      prev_t=t;
    }else{
      if(t-prev_t>=T){
        ans+=T;
      }else{
        ans+=t-prev_t;
      }
      prev_t=t;
    }
  }
  ans+=T;
  std::cout<<ans<<'\n';
  return 0;
}