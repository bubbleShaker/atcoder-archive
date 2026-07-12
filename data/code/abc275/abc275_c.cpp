#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    set<P> st;
    vector<P> ps;
    rep(i,9) {
        string s;
        cin >> s;
        rep(j,9) {
            if (s[j] == '#') {
                st.emplace(i,j);
                ps.emplace_back(i,j);
            }
        }
    }
    
    int n = ps.size();
    int ans = 0;
    rep(ai,n)rep(bi,n) if(ai!=bi) {
        P a = ps[ai], b = ps[bi];
        int di = b.first-a.first;
        int dj = b.second-a.second;
        P c(b.first-dj, b.second+di);
        P d(c.first-di, c.second-dj);
        if(st.count(c) && st.count(d)) {
            ans++;
        }
    }
    ans /= 4;
    cout << ans << endl;
    return 0;
}