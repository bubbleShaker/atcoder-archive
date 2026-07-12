#include <iostream>
#include <cmath>
int main(){
  const int INF=2e9;
  int n;
  double t,a;
  std::cin>>n>>t>>a;
  double min=(double)INF;
  int min_idx;
  for(int i=0;i<n;i++){
    double h;
    std::cin>>h;
    double ave=t-h*0.006;
    double diff=std::abs(a-ave);
    if(diff<min){
      min=diff;
      min_idx=i;
    }
  }
  std::cout<<min_idx+1<<'\n';
  return 0;
}