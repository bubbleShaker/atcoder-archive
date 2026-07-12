#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int sum=0;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      sum+=i*j;
    }
  }
  int rem=sum-n;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      if(rem==i*j){
        std::cout<<i<<" x "<<j<<'\n';
      }
    }
  }
}