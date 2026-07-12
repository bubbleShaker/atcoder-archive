#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    const long long INF=(long long)1e18;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,-INF));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>i)continue;
            dp[i][j]=dp[i-1][j-1]+j*a[i];
            if(dp[i-1][j]!=-INF){
                dp[i][j]=max(dp[i-1][j-1]+j*a[i],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}