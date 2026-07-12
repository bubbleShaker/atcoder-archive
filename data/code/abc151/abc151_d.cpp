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
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    Int ans = 0;
    rep(i,h) {
        rep(j,w) {
            if(s[i][j] == '#') continue;
            rep(k,h) {
                rep(l,w) {
                    if(s[k][l] == '#') continue;
                    vector visited(h,vector<Int>(w,-1));
                    queue<lP> q;
                    q.emplace(i,j);
                    visited[i][j] = 0;
                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();
                        
                        rep(m,4) {
                            Int nx = x+dx[m];
                            Int ny = y+dy[m];
                            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                            if(s[nx][ny] == '#') continue;
                            if(visited[nx][ny] != -1) continue;
                            visited[nx][ny] = visited[x][y]+1;
                            q.emplace(nx,ny);
                        }
                    }
                    chmax(ans,visited[k][l]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}