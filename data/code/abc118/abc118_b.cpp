#include <iostream>
#include <map>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::map<int,int> map;
  for(int i=0;i<n;i++){
    int k;
    std::cin>>k;
    for(int j=0;j<k;j++){
      int a;
      std::cin>>a;
      map[a]++;
    }
  }
  int ans=0;
  for(auto [val,cnt]:map){
    if(cnt==n){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}