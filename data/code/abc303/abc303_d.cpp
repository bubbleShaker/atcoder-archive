#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x,y,z;
  cin>>x>>y>>z;
  string s;
  cin>>s;
  int n=s.size();
  vector<vector<long long>> dp(2,vector<long long>(n+1));
  dp[0][0]=0;//0行目はCapsLock OFF
  dp[1][0]=z;//1行目はCapsLock ON
  for(int i=1;i<=n;i++){
    if(s[i-1]=='A'){
      dp[0][i]=min(dp[0][i-1]+y,dp[1][i-1]+z+x);
      dp[1][i]=min({dp[0][i-1]+z+x,dp[1][i-1]+x,dp[0][i-1]+y+z});
    }else{
      dp[0][i]=min({dp[0][i-1]+x,dp[1][i-1]+z+x,dp[1][i-1]+y+z});
      dp[1][i]=min(dp[0][i-1]+z+x,dp[1][i-1]+y);
    }
    // cerr<<min(dp[0][i],dp[1][i])<<endl;
  }
  cout<<min(dp[0][n],dp[1][n])<<endl;
  return 0;
}