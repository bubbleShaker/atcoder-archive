#include <iostream>
#include <numbers>
#include <cmath>
#include <iomanip>
int main(){
  double a,b,h,m;
  std::cin>>a>>b>>h>>m;
  double PI=std::numbers::pi;
  double h_deg=2*PI*(h/12)+(((2*PI)/60)*m)/12;
  double m_deg=2*PI*(m/60);
  double deg=std::min(std::abs(h_deg-m_deg),2*PI-std::abs(h_deg-m_deg));
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<std::sqrt(a*a+b*b-2*a*b*std::cos(deg))<<'\n';
  return 0;
}