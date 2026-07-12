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
    vector<Int> a(n);
    rep(i,n) cin >> a[i];
    vector<Int> r(n+1);
    rep(i,n) r[i+1] = r[i] + a[i];
    vector<Int> da(n);
    rep(i,n) da[i] = a[i]*a[i];
    ll sum = 0;
    rep(i,n) sum += da[i];
    ll csum = 0;
    rep(i,n-1) {
        csum += a[i]*(r[n]-r[i+1]);
    }
    ll ans = (n-1)*sum-2*csum;
    cout << ans << endl;
    return 0;
}