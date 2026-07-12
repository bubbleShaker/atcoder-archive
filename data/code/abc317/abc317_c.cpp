#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<vector<ll>> d(n+1, vector<ll>(n+1));
    rep(i,m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        d[a][b] = c;
        d[b][a] = c;
    }
    ll ans = 0;
    
    vector<bool> c(n+1);
    
    auto dfs = [&](auto f, int v, ll dist) -> void {
        if(c[v] == true) return;
        c[v] = true;
        for(int t : g[v]) {
            f(f,t,dist+d[v][t]);
        }
        ans = max(ans,dist);
        c[v] = false;;
        return;
    };
    
    for(int i = 1; i <= n; i++) {
        dfs(dfs,i,0);
    }
    cout << ans << endl;
    return 0;
}
