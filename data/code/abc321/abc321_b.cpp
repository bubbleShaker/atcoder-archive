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
    
    Int n, x;
    cin >> n >> x;
    vector<Int> a(n-1);
    rep(i,n-1) cin >> a[i];
    Int ans = 1e18;
    for(Int i = 0; i <= 100; i++) {
        vector<Int> cp = a;
        cp.push_back(i);
        sort(all(cp));
        Int sum = 0;
        rep(j,cp.size()) {
            if(j == 0 || j+1 == cp.size()) continue;
            sum += cp[j];
        }
        if(sum < x) continue;
        if(sum >= x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}