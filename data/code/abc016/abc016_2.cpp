#include <iostream>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  if(a+b==c&&a-b==c){
    std::cout<<"?"<<'\n';
  }else if(a+b==c){
    std::cout<<"+"<<'\n';
  }else if(a-b==c){
    std::cout<<"-"<<'\n';
  }else{
    std::cout<<"!"<<'\n';
  }
  return 0;
}