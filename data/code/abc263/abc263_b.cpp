#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> p(n+1);
  for(int i=2;i<=n;i++){
    std::cin>>p[i];
  }
  int ans=0;
  int now=n;
  while(now!=1){
    now=p[now];
    ans++;
  }
  std::cout<<ans<<'\n';
  return 0;
}