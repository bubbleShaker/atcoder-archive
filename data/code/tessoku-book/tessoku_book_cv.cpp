#include <bits/stdc++.h>
using namespace std;
int n;
vector<double> x,y;
void input(){
    cin>>n;
    x.resize(n+1);
    y.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
}
double dist(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
void solve(){
    const double INF=1e9;
    const int MAX=(1<<n)-1;
    vector dp(MAX+100,vector<double>(n+1,INF));
    dp[0][1]=0;
    for(int i=0;i<=MAX;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int st=i|(1<<(k-1));
                if(dp[i][j]!=INF){
                    dp[st][k]=min(dp[st][k],dp[i][j]+dist(j,k));
                }
            }
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<dp[MAX][1]<<endl;
}
int main(){
    input();
    solve();
    return 0;
}