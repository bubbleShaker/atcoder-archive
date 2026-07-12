#include <iostream>
#include <vector>
#include <set>
int main(){
  int n,q;
  std::cin>>n>>q;
  std::vector<int> deg(n);
  std::vector<std::set<int>> var_set(n+1); //各頂点の接続情報を記録,1-indexed
  int ans=n;
  while(q--){
    int type;
    std::cin>>type;
    if(type==1){
      int u,v;
      std::cin>>u>>v;
      if(deg[u]==0){ //もともと接続していないならans--
        ans--;
      }
      if(deg[v]==0){ //同様
        ans--;
      }
      deg[u]++;
      deg[v]++;
      //接続している頂点の情報を記録
      var_set[u].insert(v);
      var_set[v].insert(u);
      std::cout<<ans<<'\n';
    }else{
      int v;
      std::cin>>v;
      if(deg[v]!=0){
        ans++; //削除する頂点が接続しているなら
      }
      deg[v]=0; //削除する頂点の次数は0に
      //配列を変化させているのでバクるかも
      for(int u:var_set[v]){
        deg[u]--;
        var_set[u].erase(v); //相手の接続集合から自分を削除
        if(deg[u]==0){ //次数0になったらans++
          ans++;
        }
      }
      var_set[v].clear(); //削除する頂点の接続集合全部削除
      std::cout<<ans<<'\n';
    }
  }
  return 0;
}