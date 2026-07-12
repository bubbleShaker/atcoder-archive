#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<int,vector<int>> mp;
    rep(i,n) {
        int si = (int)s[i].size();
        mp[i] = vector<int>(27);
        rep(j,si) {
            mp[i][s[i][j]-'a']++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> p(n);
        rep(j,i) {
            p[j] = 1;
        }
        sort(p.begin(), p.end());
        do {
            vector<int> bv(27);
            rep(j,n) {
                if(p[j] == 1) {
                    vector<int> tv = mp[j];
                    rep(k,27) {
                        if(tv[k]) {
                            bv[k]++;
                        }
                    }
                }
            }
            int c = 0;
            rep(j,27) {
                if(bv[j] == k) c++;
            }
            ans = max(ans,c);
        }while(next_permutation(p.begin(), p.end()));
    }
    cout << ans << endl;
    return 0;
}
