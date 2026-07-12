#include <iostream>
#include <algorithm>
int main(){
  long long a,b,c,d;
  std::cin>>a>>b>>c>>d;
  std::cout<<std::max({b*d,a*c,b*c,a*d})<<'\n';
  return 0;
}