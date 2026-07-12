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
using dT = tuple<double,double,double,double>;
using dII = tuple<double,Int,Int>;
using mint = modint1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    Int n;
    cin >> n;
    priority_queue<lT,vector<lT>,greater<lT>> q;
    vector<lP> vx, vy;
    rep(i,n) {
        Int x, y;
        cin >> x >> y;
        vx.emplace_back(x,i);
        vy.emplace_back(y,i);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    rep(i,n-1) {
        auto [x1,u] = vx[i];
        auto [x2,v] = vx[i+1];
        Int dist = abs(x1-x2);
        q.emplace(dist,u,v);
    }
    rep(i,n-1) {
        auto [y1,u] = vy[i];
        auto [y2,v] = vy[i+1];
        Int dist = abs(y1-y2);
        q.emplace(dist,u,v);
    }
    dsu uf(n);
    Int ans = 0;
    Int m = q.size();
    rep(i,m) {
        auto [cost,u,v] = q.top();
        q.pop();

        if(uf.same(u,v)) continue;
        ans += cost;
        uf.merge(u,v);
    }
    cout << ans << endl;
    return 0;
}