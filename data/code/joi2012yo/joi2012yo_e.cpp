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

int dx[2][6] = {
    {1,0,-1,0,1,-1},
    {1,0,-1,0,1,-1}
};
int dy[2][6] = {
    {0,1,0,-1,-1,-1},
    {0,1,0,-1,1,1}
};

int main(){
    fio()
    int W,H;
    cin >> W >> H;
    vector fi(H+2, vector<int>(W+2,0));
    for(int x = 1; x <= H; x++)for(int y = 1; y <= W; y++) cin >> fi[x][y];
    vector seen(H+2,vector<bool>(W+2,false));
    auto rec = [&](auto self, int x, int y) -> void {
        seen[x][y] = true;
        for(int dir = 0; dir < 6; dir++) {
            int nx = x+dx[x%2][dir], ny = y+dy[x%2][dir];
            if(nx < 0 || nx >= H+2 || ny < 0 || ny > W+2) continue;
            if(fi[nx][ny] == 1) continue;
            if(!seen[nx][ny]) self(self,nx,ny);
        }
    };
    rec(rec,0,0);
    for(int x = 1; x <= H; x++)for(int y = 1; y <= W; y++)if(!seen[x][y]) fi[x][y] = 1;
    int res = 0;
    for(int x = 1; x <= H; x++)for(int y = 1; y <= W; y++) {
        if(fi[x][y] == 0) continue;
        for(int dir = 0; dir < 6; dir++) {
            int nx = x+dx[x%2][dir], ny = y+dy[x%2][dir];
            if(fi[nx][ny] == 0) res++;
        }
    }
    cout << res << endl;
    return 0 ;
}