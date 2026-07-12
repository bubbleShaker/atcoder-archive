#include <iostream>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  for(int i=1;i<=b;i++){
    if((i*a)%b==c){
      std::cout<<"YES"<<'\n';
      return 0;
    }
  }
  std::cout<<"NO"<<'\n';
  return 0;
}