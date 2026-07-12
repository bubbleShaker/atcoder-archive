#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector b(100001, vector<ll>(5));
    int mt = 0;
    rep(i,n) {
        int t, x;
        ll a;
        cin >> t >> x >> a;
        if(i == n-1) mt = t;
        b[t][x] += a;
    }
    const ll INF = 1001001001001001001;
    vector dp(mt+1, vector<ll>(5, -INF));
    dp[0][0] = 0;
    rep(i,mt)rep(j,5) {
        for(int k = -1; k <= 1; k++) {
            if(j+k < 0 || j+k >= 5) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j+k]);
        }
        dp[i+1][j] += b[i+1][j];
    }
    ll ans = 0;
    rep(i,5) {
        ans = max(dp[mt][i], ans);
    }
    cout << ans << endl;
    return 0;
}
