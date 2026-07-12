#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    const int MOD = 998244353;
    string s;
    cin >> s;
    int n = s.size();
    vector dp(n+1, vector<int>(n+1));
    dp[0][0] = 1;
    rep(i,n) {
        rep(j,n) {
            if(s[i] != ')') {
                dp[i+1][j+1] += dp[i][j] ;
                dp[i+1][j+1] %= MOD;
            }
            if(s[i] != '(' && j > 0) {
                dp[i+1][j-1] += dp[i][j];
                dp[i+1][j-1] %= MOD;
            }
        }
    }
    
    cout << dp[n][0] << endl;
    return 0;
}