#include <iostream>
int main(){
  long long x,y;
  std::cin>>x>>y;
  long long now=x;
  int cnt=1;
  while(now<y){
    now*=2;
    cnt++;
  }
  if(now>y){
    cnt--;
  }
  std::cout<<cnt<<'\n';
  return 0;
}