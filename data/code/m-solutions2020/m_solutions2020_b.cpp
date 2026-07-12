#include <iostream>
int main(){
  int a,b,c,k;
  std::cin>>a>>b>>c>>k;
  int cnt=0;
  while(b<=a){
    cnt++;
    b*=2;
  }
  while(c<=b){
    cnt++;
    c*=2;
  }
  if(cnt<=k){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}