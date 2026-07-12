#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int ans=0;
  for(int i=1;i<=n;i++){
    int a;
    std::cin>>a;
    if(i%2==1&&a%2==1){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}