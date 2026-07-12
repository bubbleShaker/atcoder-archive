#include <iostream>
#include <utility>
int main(){
  long long a,b,c,d;
  std::cin>>a>>b>>c>>d;
  if(a==c){
    std::cout<<"Yes"<<'\n';
    return 0;
  }else if(a>c){
    std::swap(a,c);
    std::swap(b,d);
  }
  if(c<=b){
    std::cout<<"Yes"<<'\n';
    return 0;
  }
  std::cout<<"No"<<'\n';
  return 0;
}