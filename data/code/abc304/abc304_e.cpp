#include <iostream>
#include <atcoder/dsu>
#include <utility>
#include <set>
int main(){
  int n,m;
  std::cin>>n>>m;
  atcoder::dsu uf(n);
  for(int i=0;i<m;i++){
    int u,v;
    std::cin>>u>>v;
    u--;v--;
    uf.merge(u,v);
  }
  std::set<std::pair<int,int>> set;
  int k;
  std::cin>>k;
  for(int i=0;i<k;i++){
    int x,y;
    std::cin>>x>>y;
    x--;y--;
    set.insert({uf.leader(x),uf.leader(y)});
    set.insert({uf.leader(y),uf.leader(x)});
  }
  int q;
  std::cin>>q;
  while(q--){
    int p,q;
    std::cin>>p>>q;
    p--;q--;
    if(set.count({uf.leader(p),uf.leader(q)})){
      std::cout<<"No"<<'\n';
    }else{
      std::cout<<"Yes"<<'\n';
    }
  }
  return 0;
}