#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;

int main(){
  const ll INF=4e18;
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<P> ab(n);
    for(int i=0;i<n;i++)cin>>ab[i].first;
    for(int i=0;i<n;i++)cin>>ab[i].second;
    sort(ab.begin(),ab.end());
    priority_queue<ll> pq;
    ll b_sum=0;
    for(int i=0;i<k;i++){
      pq.push(ab[i].second);
      b_sum+=ab[i].second;
    }
    ll a_max=ab[k-1].first;
    ll ans=a_max*b_sum;
    for(int i=k;i<n;i++){
      pq.push(ab[i].second);
      b_sum+=ab[i].second;
      b_sum-=pq.top();
      pq.pop();
      a_max=ab[i].first;
      ans=min(ans,a_max*b_sum);
    }
    cout<<ans<<endl;
  }
  return 0;
}