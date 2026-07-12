#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    const Int MOD = 1e5;
    Int n, m;
    cin >> n >> m;
    vector<Int> dist(n-1);
    rep(i,n-1) cin >> dist[i];
    vector<Int> a(m);
    rep(i,m) cin >> a[i];
    vector<Int> s(n);
    rep(i,n-1) {
        s[i+1] = s[i]+dist[i];
    }
    Int from = 0;
    Int ans = 0;
    rep(i,m) {
        Int to = from+a[i];
        ans += abs(s[to]-s[from])%MOD;
        ans %= MOD;
        from = to;
    }
    cout << ans << endl;
    return 0;
}