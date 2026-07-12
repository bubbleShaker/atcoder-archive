#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

ll c3(ll n) {
    return n*(n-1)*(n-2)/6;
}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(n+1);
    vector<ll> sum(n+1);
    ll ans = 0;
    rep(k,n) {
        ans += (ll)(k-1)*cnt[a[k]] - sum[a[k]];
        cnt[a[k]]++;
        sum[a[k]] += k;
    }
    
    rep(i,n) ans -= c3(cnt[i+1]);
    cout << ans << endl;
    return 0;
}
