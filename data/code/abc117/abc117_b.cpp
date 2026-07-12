#include <iostream>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  int sum=0;
  int max=0;
  for(int i=0;i<n;i++){
    int l;
    std::cin>>l;
    sum+=l;
    max=std::max(max,l);
  }
  sum-=max;
  if(max<sum){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}