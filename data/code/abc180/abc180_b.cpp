#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
int main(){
  int n;
  std::cin>>n;
  std::vector<double> x(n);
  double ans1=0;
  double ans2=0;
  double ans3=0;
  for(int i=0;i<n;i++){
    std::cin>>x[i];
    ans1+=std::abs(x[i]);
    ans2+=std::abs(x[i])*std::abs(x[i]);
    ans3=std::max(ans3,std::abs(x[i]));
  }
  ans2=std::sqrt(ans2);
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<ans1<<'\n';
  std::cout<<ans2<<'\n';
  std::cout<<ans3<<'\n';
  return 0;
}