#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> l(n);
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    
    set<ll> ps;
    rep(i,n)rep(j,n) {
        ps.insert(x[i]-l[j]-1);
        ps.insert(x[i]+l[j]);
    }
    
    ll ans = 0;
    ll pre = 0;
    for(ll p : ps) {
        bool ok = true;
        vector<ll> d(n);
        rep(i,n) d[i] = abs(x[i]-p);
        sort(d.begin(), d.end());
        rep(i,n) if(d[i] > l[i]) ok = false;
        if(ok) ans += p-pre;
        pre = p;
    }
    cout << ans << endl;
    return 0;
}