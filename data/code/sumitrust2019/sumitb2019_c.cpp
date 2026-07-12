#include <iostream>
int main(){
  int x;
  std::cin>>x;
  int rem=x%100;
  int val=x/100;
  int cnt=0;
  for(int i=5;i>=1;i--){
    int q=rem/i;
    cnt+=q;
    rem-=q*i;
  }
  if(val>=cnt){
    std::cout<<1<<'\n';
  }else{
    std::cout<<0<<'\n';
  }
  return 0;
}