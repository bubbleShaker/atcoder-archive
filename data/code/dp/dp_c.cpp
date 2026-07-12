#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector cost(n+1,vector<int>(3));
  for(int i=1;i<=n;i++){
    for(int j=0;j<3;j++){
      cin>>cost[i][j];
    }
  }
  vector dp(n+1,vector<int>(3));//dp[i][j]:i日目に行動jをした時の最大の幸福度
  for(int i=1;i<=n;i++){
    for(int j=0;j<=2;j++){
      //i日目に行動jをする場合
      for(int pj=0;pj<=2;pj++){
        if(pj==j)continue;
        dp[i][j]=max(dp[i][j],dp[i-1][pj]+cost[i][j]);
      }
    }
  }
  cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
  return 0;
}