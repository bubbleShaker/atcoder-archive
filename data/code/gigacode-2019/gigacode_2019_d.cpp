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
//using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
//using mint = modint1000000007;
using mint = modint998244353;
#define pb(a) push_back(a)
//#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
// #define rep(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define rep(i,x,y) for(Int i = x; i <= (Int)y; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

ll H, W, K, V, ans = 0;
ll A[129][129];

int main(){
    fio()
    cin >> H >> W >> K >> V;
    rep(i,1,H)rep(j,1,W) cin >> A[i][j];
    rep(i,1,H)rep(j,1,W) A[i][j]+=A[i][j-1];
    rep(i,1,H)rep(j,1,W) A[i][j]+=A[i-1][j];
    rep(lx,1,H)rep(rx,lx,H) {
        rep(ly,1,W)rep(ry,ly,W) {
            ll Area = (rx-lx+1)*(ry-ly+1);
            ll S = A[lx-1][ly-1]+A[rx][ry]-A[lx-1][ry]-A[rx][ly-1];
            if(S+Area*K<=V) ans = max(ans,Area);
        }
    }
    cout << ans << endl;
    return 0 ;
}