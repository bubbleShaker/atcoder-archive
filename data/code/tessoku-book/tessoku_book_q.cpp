#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    vector<int> a(n+1),b(n+1);
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        cin>>b[i];
    }
    for(int i=2;i<=n;i++){
        if(i==2){
            dp[i]=dp[i-1]+a[i];
        }else{
            dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i]);
        }
    }
    vector<int> ans;
    int room=n;
    while(1){
        ans.push_back(room);
        if(room==1)break;
        if(dp[room]==dp[room-1]+a[room]){
            room--;
        }else{
            room-=2;
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