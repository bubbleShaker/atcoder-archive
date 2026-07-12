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
//using mint = modint1000000007;
using mint = modint998244353;
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
    
    Int n; cin >> n;
    vector<lP> ps;
    rep(i,n) {
        Int x,y; cin >> x >> y;
        ps.emplace_back(x,y);
    }
    Int xma = 0, xmi = 1e18;
    Int yma = 0, ymi = 1e18;
    rep(i,n) {
        auto &[x,y] = ps[i];
        Int nx = x+y;
        Int ny = y-x;
        chmax(xma,nx); chmax(yma,ny);
        chmin(xmi,nx); chmin(ymi,ny);
        x = nx; y = ny;
    }
    Int ans = 0;
    rep(i,n) {
        auto [x,y] = ps[i];
        Int ret1 = abs(x - xmi);
		Int ret2 = abs(x - xma);
		Int ret3 = abs(y - ymi);
		Int ret4 = abs(y - yma);
		Int ma = max({ ret1, ret2, ret3, ret4 });
		chmax(ans,ma);
    }
    cout << ans << endl;
    return 0 ;
}