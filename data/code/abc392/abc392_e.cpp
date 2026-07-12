#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Edge=tuple<int,int,int>;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  dsu uf(n);
  vector<Edge> cable;
  for(int i=0;i<m;i++){
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
    if(uf.same(a[i],b[i])){
      cable.push_back({i,a[i],b[i]});
    }
    uf.merge(a[i],b[i]);
  }
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i=0;i<n;i++){
    pq.push(uf.leader(i));
  }
  vector<pair<int,Edge>> le_cable;
  for(auto [i,u,v]:cable){
    le_cable.push_back({uf.leader(u),{i,u,v}});
  }
  sort(le_cable.begin(),le_cable.end());
  vector<Edge> ans;
  for(auto [le,ed]:le_cable){
    auto [i,u,v]=ed;
    while(!pq.empty()&&uf.same(le,pq.top()))pq.pop();
    if(!pq.empty()){
      if(!uf.same(u,pq.top())){
        ans.push_back({i,u,pq.top()});
        uf.merge(u,pq.top());
      }
      pq.pop();
    }
  }
  cout<<ans.size()<<endl;
  for(auto [i,u,v]:ans){
    cout<<i+1<<" "<<u+1<<" "<<v+1<<endl;
  }
  return 0;
}