#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  const ll INF=1e18;
  int n,W;
  cin>>n>>W;
  vector<ll> w(n+1),v(n+1);
  for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
  const ll V_MAX=1e5;
  vector<ll> dp(V_MAX+10,INF);//dp[i][j]:i番目まで選んだ時に価値jとなる最小の重さ
  dp[0]=0;
  for(int i=1;i<=n;i++){
    for(int j=V_MAX;j>=0;j--){
      if(j-v[i]<0)continue;
      if(dp[j-v[i]]==INF)continue;
      dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
    }
  }
  ll ans=0;
  for(ll j=0;j<=V_MAX;j++){
    if(dp[j]<=W){
      ans=max(ans,j);
    }
  }
  cout<<ans<<endl;
  return 0;
}