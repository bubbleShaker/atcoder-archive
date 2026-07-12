#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector dp(h+1, vector<bool>(w+1));
    dp[1][1] = true;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(dp[i-1][j] || dp[i][j-1]) {
                if(c[i-1][j-1] == '#') continue;
                dp[i][j] = true;
            }
        }
    }
    int ans = 0;
    rep(i,h+1)rep(j,w+1) {
        if(dp[i][j]) {
            ans = max(ans, abs(i-1)+abs(j-1));
        }
    }
    cout << ans+1 << endl;
    return 0;
}
