#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> p(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i]>>a[i];
    }
    vector dp(n+1,vector<int>(n+1));
    for(int len=n-2;len>=0;len--){
        for(int l=1;l<=n-len;l++){
            int r=l+len;
            int lVal=0;
            int rVal=0;
            if(l>=2&&l<=p[l-1]&&p[l-1]<=r){
                lVal=a[l-1];
            }
            if(r<=n-1&&l<=p[r+1]&&p[r+1]<=r){
                rVal=a[r+1];
            }
            if(l>=2&&r<=n-1){
                dp[l][r]=max({dp[l-1][r+1]+lVal+rVal,dp[l-1][r]+lVal,dp[l][r+1]+rVal});
            }else if(l>=2&&r==n){
                dp[l][r]=dp[l-1][r]+lVal;
            }else if(l==1&&r<=n-1){
                dp[l][r]=dp[l][r+1]+rVal;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][i]);
    }
    cout<<ans<<endl;
    return 0;
}