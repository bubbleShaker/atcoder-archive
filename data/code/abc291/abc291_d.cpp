#include <bits/stdc++.h>
using namespace std;
int main(){
    const long long MOD=998244353;
    int n;cin>>n;
    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++){
        long long A,B;cin>>A>>B;
        a[i]=A;
        b[i]=B;
    }
    vector<vector<long long>> dp(2,vector<long long>(n));
    dp[0][0]=1;
    dp[1][0]=1;
    for(int i=1;i<n;i++){
        if(a[i-1]!=a[i])dp[0][i]+=dp[0][i-1];
        if(b[i-1]!=a[i])dp[0][i]+=dp[1][i-1];
        if(a[i-1]!=b[i])dp[1][i]+=dp[0][i-1];
        if(b[i-1]!=b[i])dp[1][i]+=dp[1][i-1];
        dp[0][i]%=MOD;
        dp[1][i]%=MOD;
    }
    long long ans=(dp[0][n-1]+dp[1][n-1])%MOD;
    cout<<ans<<endl;
    return 0;
}