#include <iostream>
int main(){
  long long a,b;
  std::cin>>a>>b;
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  std::cout<<powll(a,b)+powll(b,a)<<'\n';
  return 0;
}