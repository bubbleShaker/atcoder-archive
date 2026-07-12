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
using mint = modint1000000007;
//using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    
    Int h,w; cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    Int x = 0, y = 0;
    vector visited(h,vector<Int>(w));
    
    auto f = [&](char c) {
        if(c == 'U') return 0;
        if(c == 'R') return 1;
        if(c == 'D') return 2;
        if(c == 'L') return 3;
    };
    
    while(1) {
        visited[x][y]++;
        if(visited[x][y] >= 2) {
            cout << -1 << endl;
            return 0;
        }
        Int di = f(g[x][y]);
        Int nx = x+dx[di];
        Int ny = y+dy[di];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
            cout << x+1 << " " << y+1 << endl;
            return 0;
        }
        x = nx;
        y = ny;
    }
    return 0 ;
}