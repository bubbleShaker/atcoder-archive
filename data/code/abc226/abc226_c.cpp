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
    
    Int n; cin >> n;
    vector<vector<Int>> g(n);
    queue<Int> q;
    vector<bool> visited(n);
    vector<Int> vt(n);
    rep(i,n) {
        Int from = i;
        Int t, k;
        cin >> t >> k;
        vt[i] = t;
        rep(j,k) {
            Int to; cin >> to; to--;
            g[from].push_back(to);
        }
    }
    q.push(n-1);
    visited[n-1] = true;
    while(!q.empty()) {
        Int from = q.front();
        q.pop();
        
        for(Int to : g[from]) {
            if(visited[to]) continue;
            visited[to] = true;
            q.push(to);
        }
    }
    Int ans = 0;
    rep(i,n) {
        if(visited[i]) ans += vt[i];
    }
    cout << ans << endl;
    return 0;
}