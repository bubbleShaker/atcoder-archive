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
    
    Int h,w; cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector grd(h,vector<mint>(w));
    //vector gst(h,vector<set<Int>>(w));//移動してはいけない向きを保存
    grd[0][0]=1;
    //0:上,1:右:,2:下,3:左
    rep(i,h) {
        rep(j,w) {
            for(Int k = 1; k <= 2; k++) {
                Int nx = i+dx[k];
                Int ny = j+dy[k];
                if(nx >= h || ny >= w) continue;
                //if(gst[i][j].count(k)) continue;
                if(a[nx][ny] == '#') continue;
                grd[nx][ny]+=grd[i][j];
                //gst[nx][ny].insert((k+2)%4);
            }
        }
    }
    cout << grd[h-1][w-1].val() << endl;
    return 0 ;
}