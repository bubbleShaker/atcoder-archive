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
    
    Int n; cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    Int i = 0, j = 0, k = 0;
    rep(l,n) {
        if(a[l] == 1) i++;
        if(a[l] == 2) j++;
        if(a[l] == 3) k++;
    }
    vector dp(n+1,vector(n+1,vd(n+1)));
    vector visited(n+1,vector(n+1,vector<bool>(n+1)));
    auto f = [&](auto f,Int c1, Int c2, Int c3) -> double {
        if(c1+c2+c3 == 0) return 0.0;
        if(visited[c1][c2][c3]) return dp[c1][c2][c3];
        visited[c1][c2][c3] = true;
        double val = (double)n/(c1+c2+c3);
        if(c1>0) val += f(f,c1-1,c2,c3)*c1/(double)(c1+c2+c3);
        if(c2>0) val += f(f,c1+1,c2-1,c3)*c2/(double)(c1+c2+c3);
        if(c3>0) val += f(f,c1,c2+1,c3-1)*c3/(double)(c1+c2+c3);
        return dp[c1][c2][c3] = val;
    };
    
    f(f,i,j,k);
    sp(10)
    cout << dp[i][j][k] << endl;
    return 0 ;
}