#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <atcoder/dsu>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<std::pair<long long,std::pair<int,int>>> edge;
  for(int i=0;i<m;i++){
    int k;
    long long c;
    std::cin>>k>>c;
    std::vector<int> a(k);
    for(int j=0;j<k;j++){
      std::cin>>a[j];
      a[j]--; //0indexedに変換
    }
    for(int j=0;j<k;j++){
      edge.push_back({c,{a[j],a[(j+1)%k]}}); //辺情報の登録
    }
  }
  std::sort(edge.begin(),edge.end());
  atcoder::dsu uf(n); //n頂点の作成
  long long ans=0;
  int merge_cnt=0;
  for(int i=0;i<edge.size();i++){ //辺のコストが小さい方から
    auto [cost,uv]=edge[i];
    int u=uv.first;
    int v=uv.second;
    if(uf.leader(u)==uf.leader(v)){ //閉路を生成してしまう場合は無視
      continue;
    }
    uf.merge(u,v);
    merge_cnt++;
    ans+=cost;
  }
  if(merge_cnt!=n-1){ //連結した変数がn-1でないならば全域木は出来ていない
    std::cout<<-1<<'\n';
  }else{
    std::cout<<ans<<'\n';
  }
  return 0;
}