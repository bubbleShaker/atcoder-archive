#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
int main(){
  const int INF=2e9;
  int n,mg;
  std::cin>>n>>mg;
  std::set<std::pair<int,int>> set_g,set_h;
  for(int i=0;i<mg;i++){
    int u,v;
    std::cin>>u>>v;
    set_g.insert({u,v});
    set_g.insert({v,u});
  }
  int mh;
  std::cin>>mh;
  for(int i=0;i<mh;i++){
    int u,v;
    std::cin>>u>>v;
    set_h.insert({u,v});
    set_h.insert({v,u});
  }
  std::vector a(n+1,std::vector<int>(n+1));
  for(int i=1;i<=n-1;i++){
    for(int j=i+1;j<=n;j++){
      std::cin>>a[i][j];
      a[j][i]=a[i][j];
    }
  }
  int ans=INF;
  std::vector<int> p(n);
  std::iota(p.begin(),p.end(),1);
  do{
    int cost=0;
    for(int i=1;i<=n-1;i++){
      for(int j=i+1;j<=n;j++){
        if(set_g.count({i,j})&&set_h.count({p[i-1],p[j-1]})==false||set_g.count({i,j})==false&&set_h.count({p[i-1],p[j-1]})){
          if(p[i]<p[j]){
            cost+=a[p[i-1]][p[j-1]];
          }else{
            cost+=a[p[j-1]][p[i-1]];
          }
        }
      }
    }
    ans=std::min(ans,cost);
  }while(std::next_permutation(p.begin(),p.end()));
  std::cout<<ans<<'\n';
  return 0;
}