#include <iostream>
#include <cmath>
int main(){
  const int INF=2e9;
  int n,l;
  std::cin>>n>>l;
  int sum=0;
  int min=INF;
  for(int i=0;i<n;i++){
    int aji=l+i;
    sum+=aji;
    if(std::abs(aji)<std::abs(min)){
      min=aji;
    }
  }
  sum-=min;
  std::cout<<sum<<'\n';
  return 0;
}