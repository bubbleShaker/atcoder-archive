#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    const long long MOD=998244353;
    vector<long long> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<vector<long long>> dp(3010,vector<long long>(n+1));
    long long j=n;
    for(int long i=a[j];i<=b[j];i++){
        dp[i][j]=1;
    }
    while(j>=1){
        for(int i=0;i<=2999;i++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
        }
        for(long long k=a[j-1];k<=b[j-1];k++){
            long long valA=max(k,a[j])-1;
            if(valA<0){
                dp[k][j-1]=dp[b[j]][j];
            }else{
                dp[k][j-1]=dp[b[j]][j]-dp[valA][j];
            }
            dp[k][j-1]=(dp[k][j-1]+MOD)%MOD;
        }
        j--;
    }
    long long ans=dp[b[1]][1]%MOD;
    cout<<ans<<endl;
    return 0;
}