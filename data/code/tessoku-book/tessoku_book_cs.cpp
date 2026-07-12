#include <bits/stdc++.h>
using namespace std;
int main(){
    string ss,tt;
    cin>>ss>>tt;
    int n=ss.size();
    int m=tt.size();
    string s="_",t="_";
    s+=ss;
    t+=tt;
    vector dp(n+1,vector<int>(m+1));
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                dp[i][j]=min({dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1});
            }else{
                dp[i][j]=min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}