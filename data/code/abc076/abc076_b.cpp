#include <iostream>
int main(){
  int n,k;
  std::cin>>n>>k;
  int now=1;
  for(int i=0;i<n;i++){
    if(now<k){
      now*=2;
    }else{
      now+=k;
    }
  }
  std::cout<<now<<'\n';
  return 0;
}