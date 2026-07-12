#include <iostream>
#include <vector>
int main(){
  int n,s,t,w;
  std::cin>>n>>s>>t>>w;
  std::vector<int> a(n+1);
  for(int i=2;i<=n;i++){
    std::cin>>a[i];
  }
  int now=w;
  int ans=((s<=now&&now<=t)?1:0);
  for(int i=2;i<=n;i++){
    now+=a[i];
    if(s<=now&&now<=t){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}