#include <iostream>
#include <cmath>
int main(){
  long long x,k,d;
  std::cin>>x>>k>>d;
  long long xx=x;
  if(x<0){
    x+=(((std::abs(x)/d)<k)?std::abs(x)/d:k)*d;
    k-=(((std::abs(xx)/d)<k)?std::abs(xx)/d:k);
    if(k%2&&k!=0){
      x+=d;
    }
  }else{
    x-=(((std::abs(x)/d)<k)?std::abs(x)/d:k)*d;
    k-=(((std::abs(xx)/d)<k)?std::abs(xx)/d:k);
    if(k%2&&k!=0){
      x-=d;
    }
  }
  std::cout<<std::abs(x)<<'\n';
  return 0;
}