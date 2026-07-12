#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using lT = tuple<int,ll,ll>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<vector<P>> g(n);
    rep(i,n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; w %= 2;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    vector<int> color(n, -1);
    
    color[0] = 0; // -1：未定, 0：白, 1:黒
    queue<P> q;
    q.emplace(0,0);
    
    while(!q.empty()) {
        auto [from,cost1] = q.front();
        q.pop();
        
        for(auto [to,cost2] : g[from]) {
            if(color[to] != -1) continue;
            color[to] = (cost1+cost2)%2;
            q.emplace(to,color[to]);
        }
    }
    rep(i,n) cout << color[i] << endl;
    return 0;
}