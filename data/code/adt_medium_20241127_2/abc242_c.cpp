#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=998244353;

int main(){
  ll n;
  cin>>n;
  vector dp(10,vector<ll>(n+1));
  for(int i=1;i<=9;i++) dp[i][1]=1;
  for(int j=2;j<=n;j++){
    for(int i=1;i<=9;i++){
      if(i-1>=1) dp[i][j]+=dp[i-1][j-1],dp[i][j]%=MOD;
      dp[i][j]+=dp[i][j-1],dp[i][j]%=MOD;
      if(i+1<=9) dp[i][j]+=dp[i+1][j-1],dp[i][j]%=MOD;
    }
  }
  ll ans=0;
  for(int i=1;i<=9;i++){
    ans+=dp[i][n];
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}