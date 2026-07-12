#include <iostream>
int main(){
  long long n;
  std::cin>>n;
  int k=0;
  while((1LL<<k)<=n){
    k++;
  }
  std::cout<<--k<<'\n';
  return 0;
}