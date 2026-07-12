#include <iostream>
int main(){
  long long x;
  std::cin>>x;
  auto ceilll=[&](long long a,long long b){
    return (a+(b-1))/b;
  };
  std::cout<<((x>0)?x/10:-ceilll(-x,10))<<'\n';  
  return 0;
}