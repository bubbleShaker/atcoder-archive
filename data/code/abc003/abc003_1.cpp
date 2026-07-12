#include <iostream>
#include <iomanip>
int main(){
  double n;
  std::cin>>n;
  double ans=0;
  for(int i=1;i<=n;i++){
    ans+=i*10000;
  }
  ans/=n;
  // #include<iomanip>
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<ans<<'\n';
  return 0;
}