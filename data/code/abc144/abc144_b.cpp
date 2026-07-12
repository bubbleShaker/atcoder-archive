#include <iostream>
int main(){
  int n;
  std::cin>>n;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      if(i*j==n){
        std::cout<<"Yes"<<'\n';
        return 0;
      }
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}