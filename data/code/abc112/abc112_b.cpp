#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
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
using dII = tuple<double,Int,Int>;
using mint = modint1000000007;
using bP = pair<ll,bool>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, t;
    cin >> n >> t;
    vector<P> ps(n);
    rep(i,n) cin >> ps[i].second >> ps[i].first;
    sort(ps.begin(), ps.end());
    int mi = 1e9;
    rep(i,n) {
        auto [ti,co] = ps[i];
        if(ti <= t) {
            mi = min(co,mi);
        }
    }
    if(mi == 1e9) {
        cout << "TLE" << endl;
        return 0;
    }
    cout << mi << endl;
    return 0;
}