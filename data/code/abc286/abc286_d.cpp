#include <bits/stdc++.h>
using namespace std;
int main(){
    const int MAX=10000;
    int n,x;
    cin>>n>>x;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    vector<vector<int>> cost(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=b[i];j++){
            cost[i].push_back(a[i]*j);
        }
    }
    vector<bool> dp(MAX+1000);
    dp[0]=true;
    for(int i=1;i<=n;i++){
        int m=cost[i].size();
        vector<bool> tmp=dp;
        for(int j=0;j<m;j++){
            for(int k=MAX;k>=0;k--){
                if(k-cost[i][j]>=0){
                    if(dp[k-cost[i][j]]){
                        tmp[k]=true;
                    }
                }
            }
        }
        dp=tmp;
    }
    if(dp[x]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}