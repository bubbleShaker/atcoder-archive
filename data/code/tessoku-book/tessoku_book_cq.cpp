#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector dp(n+1,vector<bool>(600100));
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=600000;j>=0;j--){
            if((j-a[i]>=0&&dp[i-1][j-a[i]]==true)||dp[i-1][j]==true){
                dp[i][j]=true;
            }
        }
    }
    if(dp[n][s]==false){
        cout<<-1<<endl;
        return 0;
    }
    int cost=s;
    vector<int> ans;
    for(int i=n;i>=1;i--){
        if(dp[i-1][cost-a[i]]==true){
            ans.push_back(i);
            cost-=a[i];
        }
    }
    reverse(ans.begin(),ans.end());
    int m=ans.size();
    cout<<m<<endl;
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" \n"[i+1==m];
    }
    return 0;
}