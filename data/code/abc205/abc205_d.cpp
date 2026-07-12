#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> c(n);
    rep(i,n) c[i] = a[i]-i-1;
    
    rep(qi,q) {
        ll k;
        cin >> k;
        int r = lower_bound(c.begin(),c.end(),k)-c.begin();
        ll ans;
        if (r == 0) {
            ans = k;
        }else {
            ans = a[r-1] + (k-c[r-1]); 
        }
        cout << ans << endl;
    }
    return 0;
}
