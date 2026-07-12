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
using lT = tuple<ll,ll,ll>;
using mint = modint1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    Int n, m, k;
    cin >> n >> m >> k;
    priority_queue<lT,vector<lT>,greater<lT>> q;
    rep(i,m) {
        Int s, t, w;
        cin >> s >> t >> w; s--; t--;
        q.emplace(w,s,t);
    }
    dsu uf(n);
    Int ans = 0;
    Int rs = n;
    rep(i,m) {
        if(rs == k) break;
        auto [cost,u,v] = q.top();
        q.pop();

        if(uf.same(u,v)) continue;
        ans += cost;
        uf.merge(u,v);
        rs--;
    }
    cout << ans << endl;
    return 0;
}