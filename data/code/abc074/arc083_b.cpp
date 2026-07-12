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
    
    Int n;
    cin >> n;
    const Int INF = 1e18;
    vector dist(n, vector<Int>(n, INF));
    rep(i,n)rep(j,n) cin >> dist[i][j];
    vector<vector<Int>> base = dist;
    rep(k,n) {
        rep(i,n) {
            if(dist[i][k] == INF) continue;
            rep(j,n) {
                if(dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    if(dist != base) {
        cout << -1 << endl;
        return 0;
    }
    Int ans = 0;
    rep(i,n)for(int j = i; j < n; j++) ans += dist[i][j];
    rep(i,n)for(int j = i; j < n; j++) {
        if(i == j) continue;
        bool fl = false;
        rep(w,n) {
            if(w == i || w == j) continue;
            if(dist[i][j] == dist[i][w]+dist[w][j]) {
                fl = true;
                break;
            }
        }
        if(fl) ans -= dist[i][j];
    }
    cout << ans << endl;
    return 0;
}