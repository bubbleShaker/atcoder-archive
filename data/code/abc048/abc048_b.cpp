#include <iostream>
int main(){
  long long a,b,x;
  std::cin>>a>>b>>x;
  auto ceilll=[&](long long a,long long b){
    return (a+(b-1))/b;
  };
  std::cout<<b/x-ceilll(a,x)+1<<'\n';
  return 0;
}