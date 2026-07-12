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
    
    Int n, m;
    cin >> n >> m;
    const Int INF = 1e18;
    vector<vector<Int>> dist(n, vector<Int>(n, INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m) {
        Int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        dist[a][b] = t;
        dist[b][a] = t;
    }
    rep(k,n) {
        rep(i,n) {
            if(dist[i][k] == INF) continue;
            rep(j,n) {
                if(dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    priority_queue<P,vector<P>,greater<P>> q;
    rep(i,n) {
        Int ma = 0;
        rep(j,n) {
            ma = max(ma,dist[i][j]);
        }
        q.emplace(ma,i);
    }
    auto [cost,from] = q.top();
    cout << cost << endl;
    return 0;
}