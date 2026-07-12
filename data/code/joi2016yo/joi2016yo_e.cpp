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
    
    const Int INF = 1e18;
    Int n, m, k, s, p, qq;
    cin >> n >> m >> k >> s >> p >> qq;
    vector<Int> c(k);
    vector<Int> dist1(n,-1);
    rep(i,k) {
        Int C; cin >> C; C--;
        c[i] = C;
    }
    vector<vector<Int>> g(n);
    rep(i,m) {
        Int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<lP> q;
    rep(i,k) {
        q.emplace(s,c[i]);
        dist1[c[i]] = s;
    }
    while(!q.empty()) {
        auto [edge,from] = q.top();
        q.pop();
        if(dist1[from] != edge) continue;
        
        for(Int to : g[from]) {
            if(dist1[to] < dist1[from]-1) {
                dist1[to] = dist1[from]-1;
                q.emplace(dist1[to],to);
            }
        }
    }
    vector<vector<lP>> G(n);
    rep(from,n) {
        Int cost1;
        if(dist1[from] == s) continue;
        if(dist1[from] != -1) cost1 = qq;
        else cost1 = p;
        if(from == n-1) cost1 = 0;
        for(Int to : g[from]) {
            Int cost2;
            if(dist1[to] == s) continue;
            if(dist1[to] != -1) cost2 = qq;
            else cost2 = p;
            if(to == n-1) cost2 = 0;
            G[from].emplace_back(cost2,to);
            G[to].emplace_back(cost1,from);
        }
    }
    vector<Int> dist2(n,INF);
    priority_queue<lP,vector<lP>,greater<lP>> Q;
    Q.emplace(0,0);
    dist2[0] = 0;
    
    while(!Q.empty()) {
        auto [cost3,from] = Q.top();
        Q.pop();
        
        for(auto [cost4,to] : G[from]) {
            if(dist2[to] > dist2[from]+cost4) {
                dist2[to] = dist2[from]+cost4;
                Q.emplace(dist2[to],to);
            }
        }
    }
    cout << dist2[n-1] << endl;
    return 0;
}