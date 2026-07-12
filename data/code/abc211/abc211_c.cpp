#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using mint = modint1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int n = s.size();
    // const int INF = 1e9;
    vector dp(8, vector<mint>(n));
    
    const string base = "chokudai";
    rep(i,8) {
        mint tsum = 0;
        rep(j,n) {
            if(i == 0) {
                if(s[j] == base[i]) {
                    dp[i][j]++;
                }
            }else {
                if(s[j] == base[i]) {
                    dp[i][j] += tsum;
                }
                tsum += dp[i-1][j];
            }
        }
    }
    mint ans = 0;
    rep(i,n) ans += dp[7][i];
    cout << ans.val() << endl;
    return 0;
}