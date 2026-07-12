#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include<iomanip>
int main(){
  int n;
  std::cin>>n;
  std::vector<double> x(n),y(n);
  for(int i=0;i<n;i++){
    std::cin>>x[i]>>y[i];
  }
  double max=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      double dist=std::sqrt(std::abs(x[i]-x[j])*std::abs(x[i]-x[j])+std::abs(y[i]-y[j])*std::abs(y[i]-y[j]));
      max=std::max(max,dist);
    }
  }
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<max<<'\n';
  return 0;
}