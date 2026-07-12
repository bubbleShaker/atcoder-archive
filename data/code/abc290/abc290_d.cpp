#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    k--;
    int g = gcd(n,d);
    int m = n/g, e = d/g;
    int b = (ll)k*e%m;
    int i = k/m;
    int ans = b*g+i;
    cout << ans << endl;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}