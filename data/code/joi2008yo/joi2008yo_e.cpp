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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    
    Int r,c; cin >> r >> c;
    vector cell(r,vector<Int>(c));
    rep(i,r) {
        rep(j,c) {
            cin >> cell[i][j];
        }
    }
    Int ma = 0;
    //裏返す行をbit全探索
    for(Int bit = 0; bit < (1<<r); bit++) { 
        vector<vector<Int>> cp = cell;
        vector<Int> S;
        //1が立っているビットを見つけてSに格納
        for(Int i = 0; i < r; i++) {
            if(bit & (1<<i)) {
                S.push_back(i);
            }
        }
        //裏返す
        for(Int row : S) {
            rep(i,c) {
                cell[row][i] ^= 1;
            }
        }
        //1の方が多い列があったら裏返す
        rep(i,c) {
            Int cnt = 0;
            rep(j,r) {
                if(cell[j][i]) cnt++;
            }
            if(cnt >= (r+2)/2) {
                rep(j,r) {
                    cell[j][i] ^= 1;
                }
            }
        }
        //0の個数を数える
        Int zc = 0;
        rep(i,r) {
            rep(j,c) {
                if(cell[i][j] == 0) zc++;
            }
        }
        chmax(ma,zc);
        cell = cp;
    }
    cout << ma << endl;
    return 0 ;
}