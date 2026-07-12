#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
int main(){
  int xa,ya,xb,yb,xc,yc;
  std::cin>>xa>>ya>>xb>>yb>>xc>>yc;
  int ab2=((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
  int bc2=((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb));
  int ca2=((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya));
  // std::cout<<ab<<'\n';
  // std::cout<<bc<<'\n';
  // std::cout<<ca<<'\n';
  std::vector<double> vec;
  vec.push_back(ab2);
  vec.push_back(bc2);
  vec.push_back(ca2);
  std::sort(vec.begin(),vec.end());
  if(vec[0]+vec[1]==vec[2]){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}