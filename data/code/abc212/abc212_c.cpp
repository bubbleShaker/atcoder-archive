#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 1001001001;
    rep(i,n) {
        int ind = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int d;
        if(ind == 0) {
            d = abs(b[ind] - a[i]);
        }else if(ind == n) {
            d = abs(b[ind-1] - a[i]);
        }else {
            d = min(abs(b[ind] - a[i]), abs(b[ind-1] - a[i]));
        }
        ans = min(ans,d);
    }
    cout << ans << endl;
    return 0;
}
