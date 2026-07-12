#include <iostream>
#include <atcoder/dsu>
#include <vector>
#include <set>
int main(){
  int n;
  std::cin>>n;
  const int MAX=2e5;
  std::vector<int> a(n);
  atcoder::dsu uf(MAX+1); //頂点の生成
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::set<int> node_set;
  for(int i=0;i<n/2;i++){
    if(a[i]==a[n-i-1]){ //自己ループは最初から含ませない
      continue;
    }
    uf.merge(a[i],a[n-i-1]);
    node_set.insert(a[i]);
    node_set.insert(a[n-i-1]);
  }
  std::set<int> is_checked; //連結成分のチェック済み確認用
  int ans=0;
  for(auto u:node_set){ //存在している頂点について
    if(is_checked.count(uf.leader(u))){ //連結成分について確認済みなら無視
      continue;
    }
    is_checked.insert(uf.leader(u)); //確認済みにする
    ans+=uf.size(u)-1; //自身の所属する連結成分の頂点数-1が操作回数
  }
  std::cout<<ans<<'\n';
  return 0;
}