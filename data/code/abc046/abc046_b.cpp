#include <iostream>
int main(){
  int n,k;
  std::cin>>n>>k;
  auto powi=[&](int a,int b){
    int ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  int ans=k*powi(k-1,n-1);
  std::cout<<ans<<'\n';
  return 0;
}