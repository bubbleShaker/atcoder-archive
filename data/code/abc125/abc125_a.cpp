#include <iostream>
int main(){
  int a,b,t;
  std::cin>>a>>b>>t;
  int ans=0;
  for(int i=a;i<=t;i+=a){
    ans+=b;
  }
  std::cout<<ans<<'\n';
  return 0;
}