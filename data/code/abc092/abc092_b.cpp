#include <iostream>
int main(){
  int n,d,x;
  std::cin>>n>>d>>x;
  int sum=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    sum+=((d-1)/a+1);
  }
  std::cout<<sum+x<<'\n';
  return 0;
}