#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
using llP = pair<ll,ll>;

int main(void){
    const ll MOD = 998244353;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector dp(n, vector<ll>(10));
    int t1 = a[0], t2 = a[1];
    dp[1][(t1+t2)%10] += 1;
    dp[1][(t1*t2)%10] += 1;
    for(int i = 1; i <= n-2; i++) {
        rep(j,10) {
            if(dp[i][j]) {
                dp[i+1][(j+a[i+1])%10] += dp[i][j];
                dp[i+1][(j*a[i+1])%10] += dp[i][j];
                dp[i+1][(j+a[i+1])%10] %= MOD;
                dp[i+1][(j*a[i+1])%10] %= MOD;
            }
        }
    }
    rep(i,10) cout << dp[n-1][i] << endl;
    return 0;
}
