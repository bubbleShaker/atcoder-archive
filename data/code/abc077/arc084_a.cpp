#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ull ans = 0;
    rep(i,n) {
        int ai = lower_bound(a.begin(), a.end(), b[i])-a.begin();
        int ci = upper_bound(c.begin(), c.end(), b[i])-c.begin();
        ans += (ull)(ai)*(n-ci);
    }
    cout << ans << endl;
    return 0;
}