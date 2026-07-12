#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector dp(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        dp[n][i]=a[i];
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(i%2==1){
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]);
            }else{
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;
}