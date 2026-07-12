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
    
    ll ans = 0;
    rep(i,n) {
        ans *= 26;
        ans += s[i]-'A'+1;
    }
    
    cout << ans << endl;
    return 0;
}