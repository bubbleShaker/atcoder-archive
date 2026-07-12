#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using mint = modint1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<P> edge;
    rep(i,m) {
        int a, b; cin >> a >> b; a--; b--;
        edge.emplace_back(a,b);
    }
    int ans = 0;
    rep(i,m) {
        dsu uf(n);
        auto [a,b] = edge[i];
        rep(j,m) {
            if(i == j) continue;
            auto [u,v] = edge[j];
            uf.merge(u,v);
        }
        if(!uf.same(a,b)) ans++;
    }
    cout << ans << endl;
    return 0;
}