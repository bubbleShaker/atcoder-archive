#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int m;
    cin >> m;
    vector<string> ss(3);
    vector<set<int>> vs(3);
    rep(i,3) cin >> ss[i];
    rep(i,3) {
        rep(j,m){
            int c = ss[i][j]-'0';
            vs[i].insert(c);
        }
    }
    ll ans = 1e18;
    rep(i,10) {
        vector<int> p = {0,1,2};
        do {
            map<int,int> mp;
            for(int ii = 0; ii <= 2; ii++) {
                mp[ii] = p[ii];
            }
            vector<string> s(3);
            rep(ii,3) {
                s[ii] = ss[mp[ii]];
            }
            set<int> st;
            bool fl = false;
            rep(j,3) {
                if(!vs[j].count(i)) fl = true;
            }
            if(fl) continue;
            for(ll t = 0;; t++) {
                bool f0 = false, f1 = false, f2 = false;
                if(s[0][t%m]-'0' == i && !st.count(0)) {
                    st.insert(0);
                    if(st.size() == 3) {
                        ans = min(ans,t);
                        break;
                    }
                    f0 = true;
                }
                if(f0) continue;
                if(s[1][t%m]-'0' == i && !st.count(1)) {
                    st.insert(1);
                    if(st.size() == 3) {
                        ans = min(ans,t);
                        break;
                    }
                    f1 = true;
                }
                if(f1) continue;
                if(s[2][t%m]-'0' == i && !st.count(2)) {
                    st.insert(2);
                    if(st.size() == 3) {
                        ans = min(ans,t);
                        break;
                    }
                    f2 = true;
                }
                if(f2) continue;
            }
        }while(next_permutation(p.begin(), p.end()));
    }
    if(ans == 1e18) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}