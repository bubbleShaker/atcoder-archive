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

Int n, m, q;
vector<fT> ts;
Int ans = 0;
Int mi, ma;
vi now;

void input() {
    cin >> n >> m >> q;
    rep(i,q) {
        Int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        ts.emplace_back(a,b,c,d);
    }
}

void dfs(Int depth, Int siz, Int mi, Int ma) {
    if(depth == siz) {
        Int res = 0;
        rep(i,q) {
            auto [a,b,c,d] = ts[i];
            if(now[b]-now[a] == c) res += d;
        }
        chmax(ans,res);
        return;
    }else {
        for(Int j = mi; j <= ma; j++) {
            now.push_back(j);
            dfs(depth+1,siz,j,ma);
            now.pop_back();
        }
    }
}

int main(){
    fio();
    input();
    
    mi = (Int)1;
    ma = m;
    Int siz = n;
    dfs(0, siz, mi, ma);
    cout << ans << endl;
    return 0;
}