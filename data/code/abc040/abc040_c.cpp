#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=2e9;
  int n;
  cin>>n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<int> dp(n+1,INF);//dp[i]:i番目に着く最小コスト
  dp[1]=0;
  for(int i=2;i<=n;i++){
    if(i-1>=1)dp[i]=min(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
    if(i-2>=1)dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
  }
  cout<<dp[n]<<endl;
  return 0;
}