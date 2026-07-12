#include <iostream>
int main(){
  int n,x;
  std::cin>>n>>x;
  x*=100;
  int sum=0;
  for(int i=0;i<n;i++){
    int v,p;
    std::cin>>v>>p;
    sum+=v*p;
    if(sum>x){
      std::cout<<i+1<<'\n';
      return 0;
    }
  }
  std::cout<<-1<<'\n';
  return 0;
}