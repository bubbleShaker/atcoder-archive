#include <iostream>
int main(){
  int x;
  std::cin>>x;
  auto is_prime=[&](int x){
    int cnt=0;
    for(int i=2;i*i<=x;i++){
      if(x%i==0){
        cnt++;
      }
    }
    if(cnt==0){
      return true;
    }else{
      return false;
    }
  };
  for(int i=x;;i++){
    if(is_prime(i)){
      std::cout<<i<<'\n';
      return 0;
    }
  }
  return 0;
}