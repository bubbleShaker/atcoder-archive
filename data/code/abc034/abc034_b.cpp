#include <iostream>
int main(){
  int n;
  std::cin>>n;
  if(n%2==0){
    std::cout<<n-1<<'\n';
  }else{
    std::cout<<n+1<<'\n';
  }
  return 0;
}