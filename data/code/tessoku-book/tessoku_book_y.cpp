#include <bits/stdc++.h>
using namespace std;
int main(){
    const int INF=(int)1e9;
    int h,w;
    cin>>h>>w;
    vector<string> grid(h);
    for(int i=0;i<h;i++){
        cin>>grid[i];
    }
    vector dp(h,vector<long long>(w));
    dp[0][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]=='#')continue;
            if(i-1>=0){
                if(grid[i-1][j]=='.'){
                    dp[i][j]+=dp[i-1][j];
                }
            }
            if(j-1>=0){
                if(grid[i][j-1]=='.'){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
    return 0;
}