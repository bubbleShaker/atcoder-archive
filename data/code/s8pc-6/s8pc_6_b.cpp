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
    
    Int n;
    cin >> n;
    vector<Int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    Int ans = 1e18;
    rep(i,n) {
        Int start = a[i];
        rep(j,n) {
            Int sum = 0;
            Int end = b[j];
            rep(k,n) {
                sum += abs(start-a[k])+abs(b[k]-a[k])+abs(end-b[k]);
            }
            ans = min(ans,sum);
        }
    }
    cout << ans << endl;
    return 0;
}