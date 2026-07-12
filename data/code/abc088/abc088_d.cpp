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
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int H,W;
string fi[110];
int dist[110][110];

int main(){
    fio()
    cin >> H >> W;
    int wnum = 0;
    for(int i = 0; i < H; i++) {
        cin >> fi[i];
        for(int j = 0; j < W; j++) {
            if(fi[i][j] == '.') wnum++;
        }
    }
    memset(dist,-1,sizeof(dist));
    dist[0][0] = 1;
    using pint = pair<int,int>;
    queue<pint> que;
    que.push(pint(0,0));
    while(!que.empty()) {
        pint cur = que.front();
        que.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(fi[nx][ny] == '#') continue;
            if(dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y]+1;
                que.push(pint(nx,ny));
            }
        }
    }
    if(dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << wnum - dist[H-1][W-1] << endl;
    return 0 ;
}