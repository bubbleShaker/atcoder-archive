#include <iostream>
int main(){
  int d;
  std::cin>>d;
  if(d==25){
    std::cout<<"Christmas"<<'\n';
  }else if(d==24){
    std::cout<<"Christmas Eve"<<'\n';
  }else if(d==23){
    std::cout<<"Christmas Eve Eve"<<'\n';
  }else{
    std::cout<<"Christmas Eve Eve Eve"<<'\n';
  }
  return 0;
}