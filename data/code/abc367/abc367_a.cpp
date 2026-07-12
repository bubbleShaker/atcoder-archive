#include <iostream>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  if(b<c){
    if(b<a&&a<c){
      std::cout<<"No"<<'\n';
    }else{
      std::cout<<"Yes"<<'\n';
    }
  }else if(c<b){
    if(c<a&&a<b){
      std::cout<<"Yes"<<'\n';
    }else{
      std::cout<<"No"<<'\n';
    }
  }
  return 0;
}