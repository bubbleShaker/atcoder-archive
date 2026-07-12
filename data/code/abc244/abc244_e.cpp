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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    
    Int n,m,k,s,t,x; cin >> n >> m >> k >> s >> t >> x;
    s--; t--; x--;
    vector<vector<Int>> g(n);
    rep(i,m) {
        Int u,v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector dp(k+1,vector(n,vector<mint>(2)));
    
    set<Int> st;
    
    for(Int to : g[s]) {
        if(to == x) {
            dp[1][to][1]+=1;
        }else {
            dp[1][to][0]+=1;
        }
        st.insert(to);
    }
    for(Int i = 1; i < k; i++) {
        set<Int> nst;
        for(Int from : st) {
            for(Int to : g[from]) {
                if(to == x) {
                    dp[i+1][to][0]+=dp[i][from][1];
                    dp[i+1][to][1]+=dp[i][from][0];
                }else {
                    dp[i+1][to][0]+=dp[i][from][0];
                    dp[i+1][to][1]+=dp[i][from][1];
                }
                nst.insert(to);
            }
        }
        st = nst;
    }
    cout << dp[k][t][0].val() << endl;
    return 0 ;
}