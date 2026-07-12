#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

struct Edge {
    int a, b, c;
    Edge(int a, int b, int c): a(a), b(b), c(c) {}
};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> es;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        es.emplace_back(a,b,c);
    }
    const ll INF = 1e18;
    vector<ll> dist(n,INF);
    dist[0] = 0;
    rep(i,k) {
        int ei;
        cin >> ei;
        --ei;
        auto [a,b,c] = es[ei];
        dist[b] = min(dist[b], dist[a]+c);
    }
    ll ans = dist[n-1];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}