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
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double,double>;
using dII = tuple<double,Int,Int>;
using mint = modint1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    auto modpow = [&](ll a, ll n, ll mod) {
        ll res = 1;
        while(n > 0) {
            if(n&1) res = (res*a)%mod;
            a = (a*a)%mod;
            n >>= 1;
        }
        return res;
    };
    
    const Int MOD = 1000000007;
    Int n, q;
    cin >> n >> q;
    vector<Int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<lP>> g(n);
    fenwick_tree<Int> fw(n-1);
    rep(i,n-1) {
        Int dist = modpow(a[i],a[i+1],MOD);
        fw.add(i,dist);
    }
    vector<Int> c;
    c.push_back(0);
    rep(i,q) {
        Int city; cin >> city; city--;
        c.push_back(city);
    }
    c.push_back(0);
    q += 2;
    Int ans = 0;
    rep(i,q-1) {
        Int from = c[i];
        Int to = c[i+1];
        if(from > to) swap(from,to);
        Int sum = fw.sum(from,to);
        sum %= MOD;
        ans += sum;
        ans %= MOD;
    } 
    
    cout << ans << endl;
    return 0;
}