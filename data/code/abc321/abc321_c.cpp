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

Int k;
Int mi, ma;
vl now;
vl ans;

void input() {
    cin >> k;
}

void dfs(Int depth, Int siz, Int mi, Int ma) {
    if(depth == siz) {
        Int val = 0;
        rep(i,now.size()) {
            val = val*10 + now[i];
        }
        if(val == 0) return;
        ans.push_back(val);
        return;
    }else {
        for(Int j = ma; j >= mi; j--) {
            now.push_back(j);
            dfs(depth+1,siz,mi,j-1);
            now.pop_back();
        }
    }
}

void solve() {
    mi = (Int)0;
    ma = 9;
    for(Int siz = 1; siz <= 10; siz++) {
        dfs(0, siz, mi, ma);
    }
    sort(all(ans));
    cout << ans[k-1] << endl;
}

int main(){
    fio();
    input();
    
    solve();
    return 0;
}