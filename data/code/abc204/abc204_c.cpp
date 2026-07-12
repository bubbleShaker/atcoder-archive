#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
using llP = pair<ll,ll>;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    
    set<P> st;
    vector<bool> c(n+1);
    auto dfs = [&](auto f, int s, int nx) -> void {
        if(c[nx]) return;
        c[nx] = true;
        st.insert(P(s,nx));
        for(int nnx : g[nx]) {
            f(f,s,nnx);
        }
        return;
    };
    
    for(int i = 1; i <= n; i++) {
        st.insert(P(i,i));
        for(auto nx : g[i]) {
            c = vector<bool>(n+1);
            c[i] = true;
            dfs(dfs,i,nx);
        }
    }
    cout << (int)st.size() << endl;
    return 0;
}
