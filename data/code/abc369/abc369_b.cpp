#include <iostream>
#include <cmath>
int main(){
  int n;
  std::cin>>n;
  int l=-1,r=-1;
  int ans=0;
  for(int i=0;i<n;i++){
    int a;
    char s;
    std::cin>>a>>s;
    if(s=='L'){
      if(l==-1){
        l=a;
      }else{
        ans+=std::abs(l-a);
        l=a;
      }
    }else{
      if(r==-1){
        r=a;
      }else{
        ans+=std::abs(r-a);
        r=a;
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}