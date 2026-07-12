#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    
    rep(i,q) {
        int x, k;
        cin >> x >> k;
        --x;
        set<int> st;
        auto dfs = [&](auto dfs, int v, int dist) -> void {
            st.insert(v+1);
            if(dist <= 0) return;
            for(int u : g[v]) {
                dfs(dfs,u,dist-1);
            }
        };
        dfs(dfs,x,k);
        int ans = 0;
        for(int v : st) ans += v;
        cout << ans << endl;
    }
    return 0;
}
