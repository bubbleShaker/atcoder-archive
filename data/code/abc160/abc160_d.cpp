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
    
    Int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<vl> g(n);
    rep(i,n-1) {
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[x].push_back(y);
    g[y].push_back(x);
    vector<set<lP>> vs(n);
    rep(i,n) {
        queue<Int> q;
        q.push(i);
        vl dist(n,-1);
        dist[i] = 0;
        
        while(!q.empty()) {
            Int from = q.front();
            q.pop();
            
            for(Int to : g[from]) {
                if(dist[to] != -1) continue;
                dist[to] = dist[from]+1;
                q.push(to);
            }
        }
        // cout << i << endl;
        // cout << "--" << endl;
        // rep(i,n) cout << dist[i] << endl;
        // cout << "----" << endl;
        rep(j,n) {
            if(j == i) continue;
            Int from = i;
            Int to = j;
            if(from > to) swap(from,to);
            vs[dist[j]].insert(lP(from,to));
        }
    }
    for(Int k = 1; k <= n-1; k++) {
        cout << vs[k].size() << endl;
    }
    return 0;
}