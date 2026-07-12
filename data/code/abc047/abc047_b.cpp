#include <iostream>
#include <algorithm>
int main(){
  int h,w,n;
  std::cin>>h>>w>>n;
  int a1_max=0,a2_min=h,a3_max=0,a4_min=w;
  for(int i=0;i<n;i++){
    int x,y,a;
    std::cin>>x>>y>>a;
    if(a==1){
      a1_max=std::max(a1_max,x);
    }else if(a==2){
      a2_min=std::min(a2_min,x);
    }else if(a==3){
      a3_max=std::max(a3_max,y);
    }else if(a==4){
      a4_min=std::min(a4_min,y);
    }
  }
  if(a1_max<a2_min&&a3_max<a4_min){
    // std::cout<<a1_max<<'\n';
    // std::cout<<a2_min<<'\n';
    // std::cout<<a3_max<<'\n';
    // std::cout<<a4_min<<'\n';
    std::cout<<(a2_min-a1_max)*(a4_min-a3_max)<<'\n';
  }else{
    std::cout<<0<<'\n';
  }
  return 0;
}