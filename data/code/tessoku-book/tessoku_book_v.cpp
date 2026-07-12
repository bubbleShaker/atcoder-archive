#include <bits/stdc++.h>
using namespace std;
int main(){
    const int INF=(int)1e9;
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>b[i];
    }
    vector<int> dp(n+1,-INF);
    dp[1]=0;
    for(int i=1;i<=n-1;i++){
        dp[a[i]]=max(dp[a[i]],dp[i]+100);
        dp[b[i]]=max(dp[b[i]],dp[i]+150);
    }
    cout<<dp[n]<<endl;
    return 0;
}