#include <iostream>
int main(){
  int l,h,n;
  std::cin>>l>>h>>n;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    if(l<=a&&a<=h){
      std::cout<<0<<'\n';
    }else if(a<l){
      std::cout<<l-a<<'\n';
    }else{
      std::cout<<-1<<'\n';
    }
  }
  return 0;
}