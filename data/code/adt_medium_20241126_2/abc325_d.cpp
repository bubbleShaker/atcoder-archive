#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;

int main(){
  int n;
  cin>>n;
  vector<P> td(n);
  for(int i=0;i<n;i++){
    ll t,d;
    cin>>t>>d;
    td[i].first=t;
    td[i].second=t+d;
  }
  sort(td.begin(),td.end());
  priority_queue<ll,vector<ll>,greater<ll>> pq;
  ll last=0;
  ll ans=0;
  for(int i=0;i<n;i++){
    auto [in,out]=td[i];
    if(last<in) last=in,ans++;
    while(i+1<n&&td[i+1].first==in){
      pq.emplace(td[i+1].second);
      i++;
    }
    while(!pq.empty()){
      while(i+1<n&&td[i+1].first==last+1){
        pq.emplace(td[i+1].second);
        i++;
      }
      ll prod=pq.top();
      pq.pop();
      if(last<prod){
        last++;
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}