#include <iostream>
int main(){
  int n;
  std::cin>>n;
  long long sum=0;
  for(int i=0;i<n;i++){
    long long a,b;
    std::cin>>a>>b;
    long long m=b-a+1;
    sum+=(2*a+(m-1))*m/2;
  }
  std::cout<<sum<<'\n';
  return 0;
}