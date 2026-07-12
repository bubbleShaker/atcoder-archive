#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;cin>>h>>w;
    const long long MOD=(long long)1e9+7;
    vector<string> s(h);
    vector<vector<long long>> dp(h,vector<long long>(w));
    vector<long long> rswRow(h),rswCol(w);
    map<int,long long> rswNaname;
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    dp[0][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(j-1>=0){
                if(s[i][j-1]!='#'){
                    rswRow[i]+=dp[i][j-1];
                    rswRow[i]%=MOD;
                }else{
                    rswRow[i]=0;
                }
            }
            dp[i][j]+=rswRow[i];
            dp[i][j]%=MOD;
            if(i-1>=0){
                if(s[i-1][j]!='#'){
                    rswCol[j]+=dp[i-1][j];
                    rswCol[j]%=MOD;
                }else{
                    rswCol[j]=0;
                }
            }
            dp[i][j]+=rswCol[j];
            dp[i][j]%=MOD;
            if(i-1>=0&&j-1>=0){
                if(s[i-1][j-1]!='#'){
                    rswNaname[i-j]+=dp[i-1][j-1];
                    rswNaname[i-j]%=MOD;
                }else{
                    rswNaname[i-j]=0;
                }
            }
            dp[i][j]+=rswNaname[i-j];
            dp[i][j]%=MOD;
        }
    }
    long long ans=dp[h-1][w-1];
    cout<<ans<<endl;
    return 0;
}