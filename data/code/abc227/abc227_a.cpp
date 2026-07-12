#include <iostream>
int main(){
  int n,k,a;
  std::cin>>n>>k>>a;
  int now=a-1;
  for(int i=0;i<k;i++){
    now++;
    if(now==n+1){
      now=1;
    }
  }
  std::cout<<now<<'\n';
  return 0;
}