#include <iostream>
int main(){
  int x,y,z;
  std::cin>>x>>y>>z;
  x-=z;
  int ans=0;
  while(x>0){
    x-=y+z;
    ans++;
  }
  if(x<0){
    ans--;
  }
  std::cout<<ans<<'\n';
  return 0;
}