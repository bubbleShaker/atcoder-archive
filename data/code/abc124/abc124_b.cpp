#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int max=0;
  int ans=0;
  for(int i=0;i<n;i++){
    int h;
    std::cin>>h;
    if(i==0){
      max=h;
      ans++;
    }else{
      if(h>=max){
        max=h;
        ans++;
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}