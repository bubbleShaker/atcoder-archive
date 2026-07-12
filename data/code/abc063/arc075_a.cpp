#include <iostream>
#include <algorithm>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  int sum=0;
  int min=INF;
  for(int i=0;i<n;i++){
    int s;
    std::cin>>s;
    sum+=s;
    if(s%10){
      min=std::min(min,s);
    }
  }
  if(sum%10){
    std::cout<<sum<<'\n';
  }else{
    if(min==INF){
      std::cout<<0<<'\n';
    }else{
      std::cout<<sum-min<<'\n';
    }
  }
  return 0;
}