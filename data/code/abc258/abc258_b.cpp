#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
vector<int> dx = {-1, 0, 1, 0, -1, 1, 1, -1};
vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

int main(void){
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i,n) {
        ll t;
        cin >> t;
        rep(j,n){
            a[i][n-1-j] = t%10;
            t /= 10;
        }
    }
    ll ans = 0;
    rep(i,n)rep(j,n) {
        rep(k,8) {
            ll tmp = 0;
            rep(l,n) {
                int ni = (i+l*dx[k]+n)%n;
                int nj = (j+l*dy[k]+n)%n;
                ll ten = 1;
                rep(m, n-1-l){
                    ten *= 10;
                }
                tmp += a[ni][nj]*ten;
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
