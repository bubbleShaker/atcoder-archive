#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
using namespace atcoder;
using P = pair<int,int>;
using ll = long long;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    dsu uf(n);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.merge(u, v);
        deg[u]++; deg[v]++;
    }
    map<int,vector<int>> mp;
    rep(i,n) {
        int l = uf.leader(i);
        mp[l].push_back(i);
    }
    for(auto p : mp) {
        int s = (int)p.second.size();
        int e = 0;
        for(int pp : p.second) {
            e += deg[pp]; 
        }
        e /= 2;
        if(s != e) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
