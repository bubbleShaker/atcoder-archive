#include <iostream>
int main(){
  int h;
  std::cin>>h;
  long long height=0;
  int ans=0;
  for(int i=0;;i++){
    if(height>h){
      ans=i;
      break;
    }
    height+=1LL<<i;
  }
  std::cout<<ans<<'\n';
  return 0;
}