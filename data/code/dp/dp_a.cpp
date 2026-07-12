#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> h(n+1);
  for(int i=1;i<=n;i++)cin>>h[i];
  vector<int> dp(n+1);//dp[i]:i番目にたどり着く最小コスト
  for(int i=1;i<=n;i++){
    if(i==1){
      dp[i]=0;
    }else if(i==2){
      dp[i]=dp[i-1]+abs(h[i-1]-h[i]);
    }else{
      dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}