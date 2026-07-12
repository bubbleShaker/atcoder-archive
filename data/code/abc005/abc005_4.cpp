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
    
    Int n; cin >> n;
    vector d(n,vector<Int>(n));
    rep(i,n)rep(j,n) cin >> d[i][j];
    vector s(n+1,vector<Int>(n+1));
    rep(i,n)rep(j,n) {
        s[i+1][j+1] = s[i][j+1]+s[i+1][j]-s[i][j]+d[i][j];
    }
    vector<Int> size(n*n+1);
    rep(i,n) {
        for(Int j = i+1; j <= n; j++) {
            rep(k,n) {
                for(Int l = k+1; l <= n; l++) {
                    Int sz = (j-i)*(l-k);
                    Int sum = s[j][l]-s[i][l]-s[j][k]+s[i][k];
                    size[sz] = max(size[sz],sum);
                }
            }
        }
    }
    Int q; cin >> q;
    vector<Int> p(q);
    rep(i,q) cin >> p[i];
    rep(i,q) {
        Int ma = p[i];
        Int ans = 0;
        for(Int j = 1; j <= ma; j++) {
            ans = max(ans,size[j]);
        }
        cout << ans << endl;
    }
    return 0;
}