#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
    vector<bool> ch(n+1);
    
    auto dfs = [&](auto f, int c) -> void {
        cout << c << ' ';
        
        for(int nc : g[c]) {
            if(ch[nc] != false) continue;
            ch[nc] = true;
            f(f,nc);
            cout << c << ' ';
        }
        
        return;
    };
    
    ch[1] = true;
    dfs(dfs,1);
    return 0;
}
