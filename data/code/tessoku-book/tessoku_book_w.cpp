#include <bits/stdc++.h>
using namespace std;
const int INF=(int)1e9;
int n,m;
vector<vector<int>> a;
void input(){
    cin>>n>>m;
    a.resize(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}
int toDec(vector<int> a){
    int val=1;
    int ret=0;
    int n=a.size();
    reverse(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]==1){
            ret+=val;
        }
        val*=2;
    }
    return ret;
}
void solve(){
    const int MA=(1<<n)-1;
    vector<int> decA(m+1);
    for(int i=1;i<=m;i++){
        decA[i]=toDec(a[i]);
    }
    vector dp(m+1,vector<int>(MA+100,INF));
    dp[0][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=MA;j++){
            int st=j|decA[i];
            if(dp[i-1][j]!=INF){
                dp[i][st]=min(dp[i][st],dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
        }
    }
    if(dp[m][MA]!=INF){
        cout<<dp[m][MA]<<endl;
    }else{
        cout<<-1<<endl;
    }
}
int main(){
    input();
    solve();
    return 0;
}