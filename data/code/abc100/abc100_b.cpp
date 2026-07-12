#include <iostream>
int main(){
  int d,n;
  std::cin>>d>>n;
  auto powi=[&](int a,int b){
    int ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  if(n==100){
    n++;
  }
  std::cout<<powi(100,d)*n<<'\n';
  return 0;
}