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
    
    Int n; cin >> n;
    vl c(n);
    rep(i,n) cin >> c[i];
    vector<vector<Int>> g(n);
    rep(i,n-1) {
        Int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vl cnt(1001001);
    vector<bool> ans(n);
    
    auto dfs = [&](auto dfs, Int from, Int past = -1) -> void {
        cnt[c[from]]++;
        if(cnt[c[from]] == 1) ans[from] = true;
        
        for(Int to : g[from]) {
            if(to == past) continue;
            dfs(dfs,to,from);
        }
        
        cnt[c[from]]--;
    };
    
    dfs(dfs,0);
    rep(i,n) {
        if(ans[i]) cout << i+1 << endl;
    }
    return 0 ;
}