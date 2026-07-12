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
    
    Int n, m, p;
    cin >> n >> m >> p;
    vector<Int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(b));
    vector<Int> s(m+1);
    rep(i,m) s[i+1] = s[i]+b[i];
    Int ans = 0;
    rep(i,n) {
        Int serch = p-a[i];
        Int ind = upper_bound(b.begin(), b.end(),serch) - b.begin();
        ans += (m-ind)*p;
        ans += s[ind] + ind*a[i];
    }
    cout << ans << endl;
    return 0;
}