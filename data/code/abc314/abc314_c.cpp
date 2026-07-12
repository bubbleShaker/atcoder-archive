#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int>> ps(m);
    rep(i,n) ps[c[i]-1].push_back(i);
    
    string ans = s;
    rep(i,m) {
        int l = ps[i].size();
        rep(j,l) {
            ans[ps[i][(j+1)%l]] = s[ps[i][j]];
        }
    }
    cout << ans << endl;
    return 0;
}
