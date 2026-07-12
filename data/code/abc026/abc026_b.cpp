#include <iostream>
#include <numbers>
#include <iomanip>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  double ans=0;
  std::vector<double> r(n);
  for(int i=0;i<n;i++){
    std::cin>>r[i];
  }
  std::sort(r.rbegin(),r.rend());
  for(int i=0;i<n;i++){
    if(i%2==0){
      ans+=r[i]*r[i]*std::numbers::pi;
    }else{
      ans-=r[i]*r[i]*std::numbers::pi;
    }
  }
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<ans<<'\n';
  return 0;
}