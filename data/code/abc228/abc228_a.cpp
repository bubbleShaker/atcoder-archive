#include <iostream>
int main(){
  int s,t,x;
  std::cin>>s>>t>>x;
  for(int i=s;i!=t;i++){
    if(i==x){
      std::cout<<"Yes"<<'\n';
      return 0;
    }else{
      if(i+1==24){
        i=-1;
      }
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}