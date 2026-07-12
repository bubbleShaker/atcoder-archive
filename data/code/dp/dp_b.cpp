#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=2e9;
  int n,k;
  cin>>n>>k;
  vector<int> h(n+1);
  for(int i=1;i<=n;i++)cin>>h[i];
  vector<int> dp(n+1,INF);
  dp[1]=0;
  for(int i=1;i<=n;i++){
    for(int K=1;K<=k;K++){
      int j=i+K;
      if(j>n)continue;
      dp[j]=min(dp[j],dp[i]+abs(h[i]-h[j]));
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}