#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
int main(){
  double txa,tya,txb,tyb,t,v,n;
  std::cin>>txa>>tya>>txb>>tyb>>t>>v>>n;
  std::vector<double> x(n),y(n);
  for(int i=0;i<n;i++){
    std::cin>>x[i]>>y[i];
  }
  auto calc_dist=[&](std::pair<double,double> p1,std::pair<double,double> p2){
    return std::sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
  };
  double can_dist=t*v;
  for(int i=0;i<n;i++){
    double dist1=calc_dist({txa,tya},{x[i],y[i]});
    double dist2=calc_dist({x[i],y[i]},{txb,tyb});
    if(can_dist>=dist1+dist2){
      std::cout<<"YES"<<'\n';
      return 0;
    }
  }
  std::cout<<"NO"<<'\n';
  return 0;
}