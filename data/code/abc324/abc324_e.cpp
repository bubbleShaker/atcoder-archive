#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vd = vector<double>;
using vl = vector<ll>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
//using mint = modint1000000007;
using mint = modint998244353;
#define pb(a) push_back(a)
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

ll n;
string s[500001], t;
ll a[500001], b[500001], c[500001];

ll calc(const string &s, const string &t) {
    ll g = 0;
    for(auto c : s) {
        if(g >= (int)t.size()) break;
        if(c == t[g]) g++;
    }
    return g;
}

int main(){
    fio()
    
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> s[i];
    
    for(int i = 1; i <= n; i++) a[i] = calc(s[i], t);
    reverse(all(t));
    for(int i = 1; i <= n; i++) {
        reverse(all(s[i]));
        b[i] = calc(s[i],t);
        c[b[i]]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll l = (ll)t.size()-a[i];
        for(int j = l; j <= t.size(); j++) {
            ans+=c[j];
        }
    }
    cout << ans << endl;
    return 0 ;
}