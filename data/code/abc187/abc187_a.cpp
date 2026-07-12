#include <iostream>
#include <algorithm>
int main(){
  int a,b;
  std::cin>>a>>b;
  auto s=[&](int n){
    int ret=0;
    ret+=n%10;
    n/=10;
    ret+=n%10;
    n/=10;
    ret+=n%10;
    return ret;
  };
  std::cout<<std::max(s(a),s(b))<<'\n';
  return 0;
}