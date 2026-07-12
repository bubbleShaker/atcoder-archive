#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
using llP = pair<ll,ll>;

int main(void){
    int n;
    ll x;
    cin >> n >> x;
    vector<vector<int>> a(n);
    rep(i,n) {
        int l;
        cin >> l;
        a[i] = vector<int>(l);
        rep(j,l) cin >> a[i][j];
    }
    
    int ans = 0;
    
    auto dfs = [&](auto f, int i, ll s) -> void {
        if (i == n) {
            if (s == x) ans++;
            return;
        }
        
        rep(j,a[i].size()) {
            if(s > x/a[i][j]) continue;
            f(f,i+1, s*a[i][j]);
        }
    };
    dfs(dfs,0,1);
    cout << ans << endl;
    return 0;
}
