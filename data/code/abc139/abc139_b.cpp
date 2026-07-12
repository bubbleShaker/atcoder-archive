#include <iostream>
int main(){
  int a,b;
  std::cin>>a>>b;
  int now_cnt=1;
  int ans=0;
  while(now_cnt<b){
    now_cnt+=a-1;
    ans++;
  }
  std::cout<<ans<<'\n';
  return 0;
}