#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int day=1;
  int sum=0;
  while(sum<n){
    sum+=day++;
  }
  std::cout<<--day<<'\n';
  return 0;
}