#include <iostream>
int main(){
  int n;
  std::cin>>n;
  long long max=0;
  long long ans=0;
  for(int i=0;i<n;i++){
    long long a;
    std::cin>>a;
    if(a>max){
      max=a;
    }else{
      ans+=max-a;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}