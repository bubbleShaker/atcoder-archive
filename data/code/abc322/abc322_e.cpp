#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K,p;cin>>N>>K>>p;
    const long long INF=1e18;
    vector<long long> C(N+1);
    vector<vector<int>> a(N+1,vector<int>(6));
    vector<vector<vector<vector<vector<vector<long long>>>>>> dp(N+1,vector<vector<vector<vector<vector<long long>>>>>(6,vector<vector<vector<vector<long long>>>>(6,vector<vector<vector<long long>>>(6,vector<vector<long long>>(6,vector<long long>(6,INF))))));
    for(int i=1;i<=N;i++){
        cin>>C[i];
        for(int j=1;j<=K;j++){
            cin>>a[i][j];
        }
    }
    dp[0][0][0][0][0][0]=0;
    for(int i=0;i<=N-1;i++){
        int jVal,kVal,lVal,mVal,nVal;
        dp[i+1]=dp[i];
        for(int j=0;j<=5;j++){
            if(j+a[i+1][1]>5){
                jVal=5;
            }else{
                jVal=j+a[i+1][1];
            }
            for(int k=0;k<=5;k++){
                if(k+a[i+1][2]>5){
                    kVal=5;
                }else{
                    kVal=k+a[i+1][2];
                }
                for(int l=0;l<=5;l++){
                    if(l+a[i+1][3]>5){
                        lVal=5;
                    }else{
                        lVal=l+a[i+1][3];
                    }
                    for(int m=0;m<=5;m++){
                        if(m+a[i+1][4]>5){
                            mVal=5;
                        }else{
                            mVal=m+a[i+1][4];
                        }
                        for(int n=0;n<=5;n++){
                            if(n+a[i+1][5]>5){
                                nVal=5;
                            }else{
                                nVal=n+a[i+1][5];
                            }
                            if(dp[i][j][k][l][m][n]==INF)continue;
                            // cout<<"db"<<endl;
                            // cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<n<<endl;
                            // cout<<"cost:"<<dp[i][j][k][l][m][n]+C[i+1]<<endl;
                            // cout<<"------"<<endl;
                            dp[i+1][jVal][kVal][lVal][mVal][nVal]=min(dp[i+1][jVal][kVal][lVal][mVal][nVal],dp[i][j][k][l][m][n]+C[i+1]);
                        }
                    }
                }
            }
        }
    }
    long long ans=INF;
    if(K==1){
        for(int j=p;j<=5;j++){
            ans=min(ans,dp[N][j][0][0][0][0]);
        }
    }
    if(K==2){
        for(int j=p;j<=5;j++){
            for(int k=p;k<=5;k++){
                ans=min(ans,dp[N][j][k][0][0][0]);
            }
        }
    }
    if(K==3){
        for(int j=p;j<=5;j++){
            for(int k=p;k<=5;k++){
                for(int l=p;l<=p;l++){
                    ans=min(ans,dp[N][j][k][l][0][0]);
                }
            }
        }
    }
    if(K==4){
        for(int j=p;j<=5;j++){
            for(int k=p;k<=5;k++){
                for(int l=p;l<=5;l++){
                    for(int m=p;m<=5;m++){
                        ans=min(ans,dp[N][j][k][l][m][0]);
                    }
                }
            }
        }
    }
    if(K==5){
        for(int j=p;j<=5;j++){
            for(int k=p;k<=5;k++){
                for(int l=p;l<=5;l++){
                    for(int m=p;m<=5;m++){
                        for(int n=p;n<=5;n++){
                            ans=min(ans,dp[N][j][k][l][m][n]);
                        }
                    }
                }
            }
        }
    }
    if(ans==INF){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}