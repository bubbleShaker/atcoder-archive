#include <iostream>
int main(){
  int n,m;
  std::cin>>n>>m;
  int sum=0;
  for(int i=0;i<m;i++){
    int a;
    std::cin>>a;
    sum+=a;
  }
  if(n>=sum){
    std::cout<<n-sum<<'\n';
  }else{
    std::cout<<-1<<'\n';
  }
  return 0;
}