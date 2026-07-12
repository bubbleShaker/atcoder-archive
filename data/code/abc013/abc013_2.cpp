#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
int main(){
  int a,b;
  std::cin>>a>>b;
  if(a>b)std::swap(a,b);
  std::cout<<std::min(std::abs(b-a),a+10-b)<<'\n';
  return 0;
}