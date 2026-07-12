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
    int n3 = n*3;
    vector<ll> a(n3);
    rep(i,n3) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    rep(i,n) {
        ans += a[i*2+1];
    }
    cout << ans << endl;
    return 0;
}