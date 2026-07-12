#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector<vector<long long>> dp(2,vector<long long>(n+1));
    dp[0][0]=1;
    dp[1][0]=1;
    for(int j=0;j<n;j++){
        if(s[j]=="AND"){
            dp[0][j+1]+=dp[0][j];
            dp[1][j+1]+=dp[0][j]+2*dp[1][j];
        }
        if(s[j]=="OR"){
            dp[0][j+1]+=2*dp[0][j]+dp[1][j];
            dp[1][j+1]+=dp[1][j];
        }
    }
    cout<<dp[0][n]<<endl;
    return 0;
}