#include <iostream>
int main(){
  int a,b,c,k;
  std::cin>>a>>b>>c>>k;
  int ans=0;
  if(a>=k){
    ans=k;
  }else if(a+b>=k){
    ans=a;
  }else if(a+b+c>=k){
    int rem=k-(a+b);
    ans=a-rem;
  }
  std::cout<<ans<<'\n';
  return 0;
}