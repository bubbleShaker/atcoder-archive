#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    set<int> setA;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        setA.insert(a);
    }
    vector<long long> dp(n+1);
    const long long MOD=(long long)1e9+7;
    dp[0]=1;
    for(int i=0;i<=n;i++){
        if(i+1<=n&&setA.count(i+1)==false){
            dp[i+1]+=dp[i];
            dp[i+1]%=MOD;
        }
        if(i+2<=n&&setA.count(i+2)==false){
            dp[i+2]+=dp[i];
            dp[i+2]%=MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}