#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> x(n+1, vector<int>(10));
    rep(i,n) {
        int c = s[i]-'0';
        x[i+1] = x[i];
        x[i+1][c] ^= 1;
    }
    map<vector<int>,int> mp;
    rep(i,n+1) mp[x[i]]++;
    
    ll ans = 0;
    for(auto p : mp) {
        ll n = p.second;
        ans += n*(n-1)/2;
    }
    cout << ans << endl;
    return 0;
}