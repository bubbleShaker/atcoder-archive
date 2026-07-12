#include <iostream>
int main(){
  int n,m;
  std::cin>>n>>m;
  auto powi=[&](int a,int b){
    int ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  std::cout<<(1900*m+100*(n-m))*powi(2,m)<<'\n';
  return 0;
}