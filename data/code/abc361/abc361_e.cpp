#include <iostream>
#include <vector>
#include <utility>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::vector<std::pair<int,long long>>> g(n);
  long long sum_cost=0;
  for(int i=0;i<n-1;i++){
    int a,b;
    long long c;
    std::cin>>a>>b>>c;
    a--;b--;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
    sum_cost+=2*c;
  }
  std::set<int> one_set;
  for(int i=0;i<n;i++){
    if(g[i].size()==1){ //次数が1ならsetに追加
      one_set.insert(i);
    }
  }
  auto f=[&](int start){
    long long max=0;
    int ret;
    auto dfs=[&](auto dfs,int p,int u,long long cost)->void{
      if(one_set.count(u)&&u!=start){ //開始頂点でない&&次数1の頂点ならコストを更新
        if(max<cost){
          max=cost;
          ret=u;
        }
      }
      for(auto [v,c]:g[u]){
        if(v==p){ //訪れた頂点なら遷移しない
          continue;
        }
        dfs(dfs,u,v,cost+c);
      }
    };
    dfs(dfs,-1,start,0);
    return ret;
  };
  int node1=f(0);
  int node2=f(node1);
  long long dia_cost;
  auto dfs=[&](auto dfs,int p,int u,long long cost)->void{
    if(u==node2){ //node2に辿り着いたらcostをreturn
      dia_cost=cost;
      return;
    }
    for(auto [v,c]:g[u]){
      if(v==p){ //訪れた頂点なら遷移しない
        continue;
      }
      dfs(dfs,u,v,cost+c);
    }
  };
  dfs(dfs,-1,node1,0);
  // std::cout<<node1<<" "<<node2<<'\n';
  // std::cout<<dia_cost<<'\n';
  std::cout<<sum_cost-dia_cost<<'\n';
  return 0;
}