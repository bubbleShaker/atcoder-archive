#include <iostream>
int main(){
  long long x;
  int k;
  std::cin>>x>>k;
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  for(int i=0;i<k;i++){
    long long div_val=powll(10LL,i+1);
    x=((x+div_val/2)/div_val)*div_val;
  }
  std::cout<<x<<'\n';
  return 0;
}