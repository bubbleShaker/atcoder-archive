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
    vector<Int> a(n);
    rep(i,n) cin >> a[i];
    set<Int> st;
    rep(i,n) st.insert(a[i]);
    map<Int,Int> mp;
    Int ind = 0;
    for(Int val : st) {
        mp[val] = ind;
        ind++;
    }
    rep(i,n) {
        cout << mp[a[i]] << endl;
    }
    
    return 0;
}