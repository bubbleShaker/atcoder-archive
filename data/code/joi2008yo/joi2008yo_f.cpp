#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using lT = tuple<int,ll,ll>;
const int INF = 1e9;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<P>> g(n);
    priority_queue<P, vector<P>, greater<P>> q;
    rep(i,k) {
        int v;
        cin >> v;
        vector<int> dist(n, INF);
        if(v == 0) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            q.emplace(dist[a] = 0, a);
            while(!q.empty()) {
                auto [_,from] = q.top();
                q.pop();
                for(auto [c,to] : g[from]) {
                    if(dist[to] > dist[from]+c) {
                        q.emplace(dist[to] = dist[from]+c,to);
                    }
                }
            }
            if(dist[b] == INF) cout << -1 << endl;
            else cout << dist[b] << endl;
        }else {
            int c, d, e;
            cin >> c >> d >> e;
            c--; d--;
            g[c].emplace_back(e,d);
            g[d].emplace_back(e,c);
        }
    }
    return 0;
}