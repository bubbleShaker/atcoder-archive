#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    string s="_";
    s+=ss;
    vector dp(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
    }
    for(int i=1;i<=n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=2;
        }else{
            dp[i][i+1]=1;
        }
    }
    for(int len=2;len<=n-1;len++){
        for(int l=1;l<=n-len;l++){
            int r=l+len;
            if(s[l]==s[r]){
                dp[l][r]=max({dp[l+1][r-1]+2,dp[l][r-1],dp[l+1][r]});
            }else{
                dp[l][r]=max(dp[l][r-1],dp[l+1][r]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}