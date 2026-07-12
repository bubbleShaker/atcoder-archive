#include <iostream>
int main(){
  int x,a,b;
  std::cin>>x>>a>>b;
  if(b<=a){
    std::cout<<"delicious "<<'\n';
  }else if(b<=a+x){
    std::cout<<"safe"<<'\n';
  }else{
    std::cout<<"dangerous "<<'\n';
  }
  return 0;
}