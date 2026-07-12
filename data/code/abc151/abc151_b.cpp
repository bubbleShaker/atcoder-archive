#include <iostream>
#include <vector>
int main(){
  int n,k,m;
  std::cin>>n>>k>>m;
  std::vector<int> a(n-1);
  int sum=0;
  for(int i=0;i<n-1;i++){
    std::cin>>a[i];
    sum+=a[i];
  }
  int ret=m*n-(sum);
  if(ret>k){
    std::cout<<-1<<'\n';
  }else if(ret<0){
    std::cout<<0<<'\n';
  }else{
    std::cout<<ret<<'\n';
  }
  return 0;
}