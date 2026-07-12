#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using mint = modint1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    Int n; cin >> n;
    vector<Int> c(n);
    rep(i,n) cin >> c[i];
    sort(c.begin(), c.end());
    mint ans = 1;
    rep(i,n) {
        mint tmp = i;
        ans *= c[i]-tmp;
    }
    cout << ans.val() << endl;
    return 0;
}