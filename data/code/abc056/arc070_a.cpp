#include <iostream>
int main(){
  long long x;
  std::cin>>x;
  long long sum=0;
  for(long long i=1;;i++){
    sum+=i;
    if(sum>=x){
      std::cout<<i<<'\n';
      return 0;
    }
  }
  return 0;
}