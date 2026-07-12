#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int m=n/4;
  int l=n/7;
  for(int i=0;i<=m;i++){
    for(int j=0;j<=l;j++){
      if(4*i+7*j==n){
        std::cout<<"Yes"<<'\n';
        return 0;
      }
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}