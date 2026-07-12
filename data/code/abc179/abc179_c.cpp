#include <iostream>
int main(){
  int n;
  std::cin>>n;
  long long ans=0;
  for(int i=1;i<=n;i++){
    int m=n/i;
    ans+=(long long)m;
    if(i*m==n){
      ans--;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}