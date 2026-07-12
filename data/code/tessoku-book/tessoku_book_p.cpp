#include <bits/stdc++.h>
using namespace std;
int main(){
    const int INF=(int)1e8;
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        cin>>b[i];
    }
    vector<int> dp(n+1,INF);
    dp[1]=0;
    for(int i=1;i<=n-1;i++){
        dp[i+1]=min(dp[i]+a[i+1],dp[i+1]);
        if(i+2<=n){
            dp[i+2]=min(dp[i]+b[i+2],dp[i+2]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}