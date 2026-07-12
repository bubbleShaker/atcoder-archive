#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using mint = modint998244353;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, q;
    cin >> n >> m >> q;
    auto sum2 = [&](int x, int y, mint a) {
        mint res = a+(a+mint(x-1)*m*2+(y-1)*2);
        return res*x*y/2;
    };
    auto sum = [&](int x, int y) {
        mint res;
        res += sum2((x+1)/2, (y+1)/2, 1);
        res += sum2(x/2, y/2, m+2);
        return res;
    };
    rep(qi,q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --c;
        mint ans;
        ans += sum(b,d);
        ans -= sum(a,d);
        ans -= sum(b,c);
        ans += sum(a,c);
        cout << ans.val() << '\n';
    }
    return 0;
}