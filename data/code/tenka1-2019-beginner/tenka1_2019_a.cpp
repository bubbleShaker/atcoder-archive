#include <iostream>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  if(a<c&&c<b||b<c&&c<a){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}