#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin>>n>>x;
  vector<int> a(n+1),b(n+1);
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
  vector dp(n+1,vector<bool>(x+1));
  dp[0][0]=true;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=x;j++){
      if(j-a[i]>=0&&dp[i-1][j-a[i]]){
        dp[i][j]=true;
      }
      if(j-b[i]>=0&&dp[i-1][j-b[i]]){
        dp[i][j]=true;
      }
    }
  }
  if(dp[n][x]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}