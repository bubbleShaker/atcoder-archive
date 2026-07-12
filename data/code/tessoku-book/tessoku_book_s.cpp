#include <bits/stdc++.h>
using namespace std;
int main(){
    const long long INF=(long long)1e18;
    int n,W;
    cin>>n>>W;
    vector<long long> w(n+1),v(n+1);
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    vector dp(n+1,vector<long long>(100100,-INF));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=100000;j++){
            if(j-w[i]>=0&&dp[i-1][j-w[i]]!=-INF){
                dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }else if(dp[i-1][j]!=-INF){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    long long ans=-INF;
    for(int i=0;i<=W;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}