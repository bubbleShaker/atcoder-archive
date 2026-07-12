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
    
    const ll INF = 1e18;
    const ll X = 1000000000000000;
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    vector<vector<pair<ll,int>>> gy(n);
    vector<vector<pair<ll,int>>> gs(n);
    rep(i,m) {
        int u, v;
        ll a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        gy[u].emplace_back(a, v);
        gy[v].emplace_back(a, u);
        gs[u].emplace_back(b, v);
        gs[v].emplace_back(b, u);
    }
    
    priority_queue<P,vector<P>,greater<P>> qy;
    priority_queue<P,vector<P>,greater<P>> qs;
    vector<ll> disty(n, INF);
    vector<ll> dists(n, INF);

    qy.emplace(disty[s] = 0, s);
    while(!qy.empty()) {
        auto [_,from] = qy.top();
        qy.pop();
        
        for(auto [tc,to] : gy[from]) {
            if(disty[to] > disty[from]+tc) {
                qy.emplace(disty[to] = disty[from]+tc, to);
            }
        }
    }
    
    qs.emplace(dists[t] = 0, t);
    while(!qs.empty()) {
        auto [_,from] = qs.top();
        qs.pop();
        
        for(auto [tc,to] : gs[from]) {
            if(dists[to] > dists[from]+tc) {
                qs.emplace(dists[to] = dists[from]+tc, to);
            }
        }
    }
        
    vector<ll> ans(n+1,INF);
    for(ll i = n-1; i >= 0; i--)
      ans[i] = min(ans[i+1], disty[i]+dists[i]);

    for(ll i=0;i<n;i++) cout<< X-ans[i] <<endl;
    
    return 0;
}