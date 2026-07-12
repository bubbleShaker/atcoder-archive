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
    
    Int n, m, t;
    cin >> n >> m >> t;
    vector<Int> a(n+1);
    for(int i = 1; i <= n-1; i++) {
        Int ro;
        cin >> ro;
        a[i] = ro;
    }
    vector<Int> b(n+1,-1);
    rep(i,m) {
        Int x, y;
        cin >> x >> y;
        b[x] = y;
    }
    Int sum = t;
    for(int i = 1; i <= n-1; i++) {
        if(b[i] != -1) {
            sum += b[i];
        }
        if(sum-a[i] <= 0) {
            cout << "No" << endl;
            return 0;
        }else {
            sum -= a[i];
        }
    }
    cout << "Yes" << endl;
    return 0;
}