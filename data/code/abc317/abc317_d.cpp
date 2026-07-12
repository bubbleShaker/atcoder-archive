#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<ll> x(n+1), y(n+1), z(n+1);
    for(int i = 1; i < n+1; i++) cin >> x[i] >> y[i] >> z[i];
    ll s = 0;
    rep(i,n) s += z[i+1];
    const ll INF = 201001001001001001;
    vector dp(n+1, vector<ll>(s+1, INF));
    vector<ll> co(n+1);
    for(ll i = 1; i < n+1; i++) {
        ll l  = (ll)(y[i]-x[i]+1)/2;
        ll k = max(l,(ll)0);
        co[i] = k;
    }
    rep(i,n+1) dp[i][0] = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j < s+1; j++) {
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            dp[i][j] = min(dp[i][j],dp[i-1][max((ll)0,j-z[i])]+co[i]);
        }
    }
    ll c = (ll)s/2+1;
    ll ans = 2001001001001001001;
    for(ll i = c; i < s+1; i++) {
        ans = min(ans,dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}