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
    
    Int n;
    double D;
    cin >> n >> D;
    vector<pair<double,double>> ps;
    rep(i,n) {
        Int x,y;
        cin >> x >> y;
        ps.emplace_back(x,y);
    }
    vector<vector<Int>> g(n);
    for(Int i = 0; i < n; i++) {
        auto [bx,by] = ps[i];
        for(Int j = i+1; j < n; j++) {
            auto [nx,ny] = ps[j];
            double d = sqrt((bx-nx)*(bx-nx)+(by-ny)*(by-ny));
            if(d <= D) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector<bool> visited(n);
    queue<Int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()) {
        Int from = q.front();
        q.pop();
        
        for(Int to : g[from]) {
            if(visited[to]) continue;
            visited[to] = true;
            q.push(to);
        }
    }
    rep(i,n) {
        if(visited[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0 ;
}