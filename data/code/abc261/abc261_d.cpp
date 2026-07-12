#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<ll> x(n+1);
    rep(i,n) cin >> x[i+1];
    vector<pair<int,ll>> ps(m);
    rep(i,m) cin >> ps[i].first >> ps[i].second;
    vector<ll> b(n+1);
    for(auto [c,y] : ps) b[c] = y;
    const ll INF = 1001001001001001001;
    vector dp(n+1, vector<ll>(n+1,-INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0){
                ll ma = 0;
                rep(k,n+1) {
                    ma = max(dp[i-1][k], ma);
                }
                dp[i][j] = ma;
            }else {
                dp[i][j] = dp[i-1][j-1]+x[i]+b[j];
            }
        }
    }
    ll ans = 0;
    rep(i,n+1) {
        ans = max(ans,dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
