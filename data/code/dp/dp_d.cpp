#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  const ll INF=1e18;
  int n,W;
  cin>>n>>W;
  vector<ll> w(n+1),v(n+1);
  for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
  vector<ll> dp(W+10,-INF);//dp[i][j]:i個目まで見たとき、重さがjの時の最大価値
  dp[0]=0;
  for(int i=1;i<=n;i++){
    for(int j=W;j>=0;j--){
      //i番目の商品を選んで重さjになる時の最大価値を考える
      if(j-w[i]<0)continue;
      if(dp[j-w[i]]==-INF)continue;
      dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
      // cout<<"i,j:"<<i<<" "<<j<<endl;;
      // cout<<"dp[i][j]:"<<dp[j]<<endl;
    }
  }
  ll ans=0;
  for(int j=0;j<=W;j++){
    if(dp[j]==-INF)continue;
    ans=max(ans,dp[j]);
  }
  cout<<ans<<endl;
  return 0;
}