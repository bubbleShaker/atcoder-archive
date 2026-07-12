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
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
//#define rep(i,x,y) for(Int i = x; i < (Int)y; ++i)
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
// vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int m,n;
bool isice[90][90];
bool seen[90][90];

int ans = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int y, int x, int now) {
    seen[y][x] = true;
    now++;
    ans = max(ans,now);
    rep(t,4) {
        int ny = y+dy[t], nx = x+dx[t];
        if(0 <= ny && ny < n && 0 <= nx && nx < m) {
            if(!seen[ny][nx] && isice[ny][nx]) {
                dfs(ny,nx,now);
            }
        }
    }
    seen[y][x] = false;
}

int main(){
    fio()
    cin >> m >> n;
    rep(i,n)rep(j,m) cin >> isice[i][j];
    rep(i,n)rep(j,m) {
        if(!isice[i][j]) continue;
        rep(k,n)rep(l,m) {
            seen[k][l] = false;
        }
        dfs(i,j,0);
    }
    cout << ans << endl;
    return 0 ;
}