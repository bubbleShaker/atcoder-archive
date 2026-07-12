#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
using PQ=priority_queue<P,vector<P>,greater<P>>;

int main(){
  const int INF=2e9;
  int n,w;
  cin>>n>>w;
  vector<PQ> pq(w+10);
  vector<int> x(n+10),y(n+10);
  vector<int> ans(n+10,-INF);
  for(int i=1;i<=n;i++){
    cin>>x[i]>>y[i];
    pq[x[i]].push({y[i],i});
  }
  int q;
  cin>>q;
  vector<int> t(q+10),a(q+10);
  for(int i=1;i<=q;i++){
    cin>>t[i]>>a[i];
  }
  bool end=false;
  int t_now=0;
  int t_era=0;
  while(!end){
    for(int i=1;i<=w;i++){
      if(pq[i].empty()){
        end=true;
        break;
      }
      t_era=max(t_era,t_now+pq[i].top().first);
    }
    if(end){
      break;
    }
    for(int i=1;i<=w;i++){
      ans[pq[i].top().second]=t_era;
      pq[i].pop();
      if(!pq[i].empty()){
          P new_box=make_pair(max(1,pq[i].top().first-t_era),pq[i].top().second);
          pq[i].pop();
          pq[i].push(new_box);
      }
    }
    t_now=t_era;
  }
  for(int j=1;j<=q;j++){
    if(ans[a[j]]==-INF){
      cout<<"Yes"<<endl;
    }else if(ans[a[j]]>t[j]){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}