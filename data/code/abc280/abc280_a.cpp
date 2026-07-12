#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using lT = tuple<int,ll,ll>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h)rep(j,w) {
        if(s[i][j] == '#') ans++;
    }
    cout << ans << endl;
    return 0;
}