#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
//using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio();
    
    Int n, m; cin >> n >> m;
    vl oa(n);
    rep(i,n) cin >> oa[i];
    sort(all(oa));
    Int sum = 0;
    rep(i,n) sum += oa[i];
    vl a;
    rep(i,n) a.push_back(oa[i]);
    rep(i,n) a.push_back(oa[i]);
    vl ans;
    Int s = a[0];
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(Int i = 1; i < 2*n; i++) {
        bool fl = false;
        if(a[i] == a[i-1] || a[i] == (a[i-1]+1)%m) {
            s += a[i];
            if(i == n && ans.size() == 0) {
                s -= a[i];
                ans.push_back(s);
                fl = true;
            }
        }
        else {
            ans.push_back(s);
            s = a[i];
            if(i >= 2*n) fl = true;
        }
        if(fl) break;
    }
    Int ma = 0;
    rep(i,ans.size()) {
        chmax(ma,ans[i]);
    }
    cout << sum-ma << endl;
    return 0 ;
}