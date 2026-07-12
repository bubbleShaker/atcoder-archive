#include <iostream>
int main(){
  int v,t,s,d;
  std::cin>>v>>t>>s>>d;
  if(d<v*t){
    std::cout<<"Yes"<<'\n';
  }else if(v*s<d){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}