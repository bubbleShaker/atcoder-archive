#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w; ll c;
    cin >> h >> w >> c;
    vector a(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    
    const ll INF = 1e18;
    ll ans = INF;
    
    rep(_,2) {
        vector d(h, vector<ll>(w, INF));
        rep(i,h)rep(j,w) {
            if(i) d[i][j] = min(d[i][j], d[i-1][j]);
            if(j) d[i][j] = min(d[i][j], d[i][j-1]);
            ans = min(ans, a[i][j]+(i+j)*c+d[i][j]);
            d[i][j] = min(d[i][j], a[i][j]-(i+j)*c);
        }
        
        reverse(a.begin(), a.end());
    }
    
    cout << ans << endl;
    return 0;
}