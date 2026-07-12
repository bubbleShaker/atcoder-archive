#include <iostream>
int main(){
  int n,k;
  std::cin>>n>>k;
  int sum=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      sum+=100*i+j;
    }
  }
  std::cout<<sum<<'\n';
  return 0;
}