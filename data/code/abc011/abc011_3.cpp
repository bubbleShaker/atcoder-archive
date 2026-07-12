#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=1e9;
  int n;
  int ng1,ng2,ng3;
  cin>>n>>ng1>>ng2>>ng3;
  set<int> ng_set;
  ng_set.insert(ng1);
  ng_set.insert(ng2);
  ng_set.insert(ng3);
  vector<int> dp(500,INF);
  dp[0]=0;
  for(int i=0;i<n;i++){
    if(!ng_set.count(i+1)){
      dp[i+1]=min(dp[i+1],dp[i]+1);
    }
    if(!ng_set.count(i+2)){
      dp[i+2]=min(dp[i+2],dp[i]+1);
    }
    if(!ng_set.count(i+3)){
      dp[i+3]=min(dp[i+3],dp[i]+1);
    }
  }
  if(dp[n]<=100){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}