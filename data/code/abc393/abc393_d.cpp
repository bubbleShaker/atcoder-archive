#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back

ll calc(ll N){
  if(N<=0)return 0;
  return N*(N+1)/2;
}

int main(){
  const ll INF=1e18;
  int n;
  string s;
  cin>>n>>s;
  vector<int> one_idx;
  for(int i=0;i<n;i++){
    if(s[i]=='1')one_idx.pb(i);
  }
  int one_cnt=one_idx.size();
  ll r_rsw=0;
  ll l_rsw=0;
  for(int i=1;i<one_cnt;i++){
    r_rsw+=one_idx[i]-one_idx[0]-1;
  }
  ll r_one_cnt=one_cnt-1;
  ll l_one_cnt=0;
  ll ans=INF;
  for(int next_i=1;next_i<=one_cnt;next_i++){
    ll cost=r_rsw-calc(r_one_cnt-1)+l_rsw-calc(l_one_cnt-1);
    ans=min(ans,cost);
    if(next_i==one_cnt)break;
    ll dist=one_idx[next_i]-one_idx[next_i-1];
    r_rsw-=r_one_cnt*dist;
    r_one_cnt--;
    l_one_cnt++;
    l_rsw+=l_one_cnt*dist;
  }
  cout<<ans<<endl;
  return 0;
}