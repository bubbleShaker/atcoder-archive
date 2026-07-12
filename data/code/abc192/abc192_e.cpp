#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    const Int INF = 1e18;
    Int n, m, x, y;
    cin >> n >> m >> x >> y; x--; y--;
    vector<vector<lT>> g(n);
    vector<Int> mo(m);
    rep(i,m) {
        Int a, b, t, k;
        cin >> a >> b >> t >> k; a--; b--;
        g[a].emplace_back(t,b,i);
        g[b].emplace_back(t,a,i);
        mo[i] = k;
    }
    vector<Int> dist(n,INF);
    
    priority_queue<lP,vector<lP>,greater<lP>> q;
    q.emplace(0,x);
    dist[x] = 0;
    
    int ti = clock();
    while(!q.empty() && (clock() - ti < 188 * CLOCKS_PER_SEC / 100)) {
        auto [_,from] = q.top();
        q.pop();
        
        for(auto [cost,to,edge] : g[from]) {
            Int MOD = mo[edge];
            Int ncost;
            if(dist[from]%MOD == 0) ncost = dist[from]+cost;
            else ncost = (dist[from]/MOD+1)*MOD+cost;
            if(dist[to] > ncost) {
                dist[to] = ncost;
                q.emplace(dist[to],to);
            }
        }
    }
    if(dist[y] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[y] << endl;
    return 0;
}