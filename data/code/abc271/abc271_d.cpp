#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, s;
    cin >> n >> s;
    vector<P> ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;
    vector dp(n+1, vector<bool>(10001));
    dp[0][0] = true;
    rep(i,n) {
        auto [h,t] = ps[i];
        rep(j,10001) {
            if(dp[i][j]) dp[i+1][j+h] = dp[i+1][j+t] = true;
        }
    }
    if(dp[n][s] == false) {
        cout << "No" << endl;
        return 0;
    }
    
    string ans;
    for(int i = n; i > 0; i--) {
        auto [h,t] = ps[i-1];
        if(s-h >= 0 && dp[i-1][s-h]){
            ans.push_back('H');
            s -= h;
            continue;
        }else if(s-t >= 0 && dp[i-1][s-t]) {
            ans.push_back('T');
            s -= t;
            continue;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}
