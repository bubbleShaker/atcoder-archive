#include <iostream>
int main(){
  long long h,w;
  std::cin>>h>>w;
  if(h==1||w==1){
    std::cout<<1<<'\n';
    return 0;
  }
  long long ans=0;
  auto ceili=[&](long long a,long long b){
    return (a+(b-1))/b;
  };
  for(long long i=0;i<h;i++){
    if(i%2==0){
      ans+=ceili(w,2LL);
    }else{
      ans+=w/2;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}