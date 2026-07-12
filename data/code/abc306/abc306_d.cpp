#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int n;
    cin >> n;
    vector<pair<int, ll>> ps(n+1);
    for(int i = 1; i <= n; i++) cin >> ps[i].first >> ps[i].second;
    vector dp(n+1, vector<ll>(2));
    for(int i = 1; i <= n; i++) {
        if(ps[i].first == 0) {
            dp[i][0] = max({dp[i-1][0], dp[i-1][0]+ps[i].second, dp[i-1][1]+ps[i].second});
            dp[i][1] = dp[i-1][1];
        }else if(ps[i].first == 1) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0]+ps[i].second, dp[i-1][1]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
