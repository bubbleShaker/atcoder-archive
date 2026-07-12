#include <iostream>
int main(){
  const long long INF=4e18;
  int n;
  std::cin>>n;
  long long rsw=0;
  long long min=INF;
  for(int i=0;i<n;i++){
    long long a;
    std::cin>>a;
    rsw+=a;
    min=std::min(rsw,min);
  }
  if(min>=0){
    std::cout<<rsw<<'\n';
  }else{
    std::cout<<rsw-min<<'\n';
  }
  return 0;
}