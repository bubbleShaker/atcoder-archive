#include <iostream>
#include <utility>
#include <vector>
int main(){
  std::vector<int> a(5);
  for(int i=0;i<5;i++){
    std::cin>>a[i];
  }
  if(a[4]%10==0){
    std::swap(a[3],a[4]);
  }
  int min=a[4]%10;
  for(int i=0;i<4;i++){
    if(a[i]%10!=0){
      if(a[i]%10<min){
        min=a[i]%10;
        std::swap(a[i],a[4]);
      }
    }
  }
  int ans=0;
  for(int i=0;i<4;i++){
    ans+=a[i];
    ans+=((ans%10==0)?0:10-(ans%10));
  }
  ans+=a[4];
  std::cout<<ans<<'\n';
  return 0;
}