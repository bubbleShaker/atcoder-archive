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
    
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i,n) {
        for(int j = 1; j <= n; j++){
            string res = s.substr(i,j);
            reverse(res.begin(), res.end());
            string tmp = res;
            reverse(res.begin(), res.end());
            if(tmp == res) {
                ans = max(ans, (int)tmp.size());
            }
        }
    }
    cout << ans << endl;
    return 0;
}