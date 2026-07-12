#include <iostream>
int main(){
  int n;
  std::cin>>n;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    if(a%2==0){
      if(a%3==0||a%5==0){
        continue;
      }
      std::cout<<"DENIED"<<'\n';
      return 0;
    }
  }
  std::cout<<"APPROVED"<<'\n';
  return 0;
}