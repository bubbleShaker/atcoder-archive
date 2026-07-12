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
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    
    auto rot = [&](vector<string> a) {
        vector<string> res(n, string(n, '.'));
        rep(i,n)rep(j,n) res[j][n-1-i] = a[i][j];
        return res;
    };
    
    auto normalize = [&](vector<string> a) {
        int li = n, lj = n;
        rep(i,n)rep(j,n) {
            if (a[i][j] == '#') {
                li = min(li,i);
                lj = min(lj,j);
            }
        }
        vector<string> res(n, string(n, '.'));
        rep(i,n)rep(j,n) if(a[i][j] == '#') {
            res[i-li][j-lj] = '#';
        }
        return res;
    };
    auto same = [&](vector<string> a, vector<string> b) {
        return normalize(a) == normalize(b);
    };
    
    rep(ri,4) {
        if (same(s,t)) {
            cout << "Yes" << endl;
            return 0;
        }
        t = rot(t);
    }
    cout << "No" << endl;
    return 0;
}