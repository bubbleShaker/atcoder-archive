#include <iostream>
int main(){
  int a,b;
  std::cin>>a>>b;
  int ans=a-1;
  if(a<=b){
    ans++;
  }
  std::cout<<ans<<'\n';
  return 0;
}