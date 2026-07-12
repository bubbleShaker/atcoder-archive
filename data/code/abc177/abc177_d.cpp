#include <iostream>
#include <map>
#include <atcoder/dsu>
int main(){
  int n,m;
  std::cin>>n>>m;
  atcoder::dsu dsu(n);
  for(int i=0;i<m;i++){
    int a,b;
    std::cin>>a>>b;
    a--;
    b--;
    dsu.merge(a,b);
  }
  std::map<int,int> map;
  for(int i=0;i<n;i++){
    map[dsu.leader(i)]++;
  }
  int ans=0;
  for(auto [l,cnt]:map){
    ans=std::max(ans,cnt);
  }
  std::cout<<ans<<'\n';
  return 0;
}