#include <bits/stdc++.h>
using namespace std;
using Graph=vector<set<int>>;

int main(){
  int n,k;
  cin>>n>>k;
  Graph g(n+1);
  vector<int> deg(n+1);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].insert(b);
    g[b].insert(a);
    deg[a]++;
    deg[b]++;
  }
  set<int> v;
  for(int i=0;i<k;i++){
    int tmp;
    cin>>tmp;
    v.insert(tmp);
  }
  vector<int> leaves;
  for(int v=1;v<=n;v++){
    if(deg[v]==1){//葉ならば
      leaves.push_back(v);
    }
  }
  int ans=n;
  for(auto var:leaves){
    int leaf=var;
    int parent=*g[leaf].begin();//葉の親
    while(true){
      if(v.count(leaf)){//削除してはいけない葉ならば削除しない
        break;
      }
      deg[leaf]--;
      deg[parent]--;
      g[leaf].erase(parent);
      g[parent].erase(leaf);
      ans--;
      if(deg[parent]==1){
        leaf=parent;//親を見る
        parent=*g[leaf].begin();
      }else{//親が葉でないならば終了
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}