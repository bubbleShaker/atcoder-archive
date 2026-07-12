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

int main(){
    fio()
    
    Int n, a, b, c; cin >> n >> a >> b >> c;
    vector d(n,vl(n));
    rep(i,n)rep(j,n) cin >> d[i][j];
    
    priority_queue<lP, vector<lP>, greater<lP>> q;
    vector<Int> dist1(n, INFL);
    q.emplace(dist1[0] = 0, 0);
    while(!q.empty()) {
        auto [_,from] = q.top();
        q.pop();
        for(Int to = 0; to < n; to++) {
            if(to == from) continue;
            if(dist1[to] > dist1[from]+d[from][to]*a) {
                q.emplace(dist1[to] = dist1[from]+d[from][to]*a,to);
            }
        }
    }
    vector<Int> dist2(n, INFL);
    q.emplace(dist2[n-1] = 0, n-1);
    while(!q.empty()) {
        auto [_,from] = q.top();
        q.pop();
        for(Int to = 0; to < n; to++) {
            if(to == from) continue;
            if(dist2[to] > dist2[from]+d[to][from]*b+c) {
                q.emplace(dist2[to] = dist2[from]+d[to][from]*b+c,to);
            }
        }
    }
    Int ans = INFL;
    rep(i,n) {
        chmin(ans,dist1[i]+dist2[i]);
    }
    cout << ans << endl;
    return 0 ;
}