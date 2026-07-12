#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<P> ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;
    sort(ps.begin(), ps.end());
    ll ans = 0;
    rep(i,n) {
        ans += (ll)ps[i].first * ps[i].second;
        m -= ps[i].second;
        if(m < 0) {
            m += ps[i].second;
            ans -= (ll)ps[i].first * ps[i].second;
            ans += (ll)ps[i].first * m;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}