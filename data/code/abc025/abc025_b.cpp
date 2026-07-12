#include <iostream>
#include <string>
int main(){
  int n,a,b;
  std::cin>>n>>a>>b;
  int now=0;
  for(int i=0;i<n;i++){
    std::string s;
    int d;
    std::cin>>s>>d;
    if(d<a){
      d=a;
    }else if(d>b){
      d=b;
    }
    if(s=="West"){
      now-=d;
    }else{
      now+=d;
    }
  }
  if(now<0){
    std::cout<<"West "<<-now<<'\n';
  }else if(now>0){
    std::cout<<"East "<<now<<'\n';
  }else{
    std::cout<<0<<'\n';
  }
  return 0;
}