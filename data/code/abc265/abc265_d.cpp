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
    
    Int n, p, q, R;
    cin >> n >> p >> q >> R;
    vector<Int> a(n);
    rep(i,n) cin >> a[i];
    vector<Int> r(n+1);
    rep(i,n) r[i+1] = r[i] + a[i];
    multiset<Int> st;
    map<Int,Int> mp;
    rep(i,n+1) {
        st.insert(r[i]);
        mp[r[i]] = i;
    }
    rep(i,n+1) {
        if(st.count(r[i]+p)) {
            Int j = mp[r[i]+p];
            if(st.count(r[j]+q)) {
                Int k = mp[r[j]+q];
                if(st.count(r[k]+R)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0; 
}