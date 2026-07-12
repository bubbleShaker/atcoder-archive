#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

struct Edge {
    int c, a, b, i;
    Edge(int c, int a, int b, int i=-1): c(c), a(a), b(b), i(i) {}
    bool operator<(const Edge& other) const { return c < other.c; }
};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<Edge> es;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        es.emplace_back(c,a,b);
    }
    sort(es.begin(), es.end());
    vector<Edge> qs;
    rep(i,q) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        qs.emplace_back(c,a,b,i);
    }
    vector<bool> ans(q);
    sort(qs.begin(), qs.end());
    int qi = 0;

    dsu t(n);
    for (auto [c,a,b,_] : es) {
        while(qi < q && qs[qi].c < c) {
            auto [nc,na,nb,i] = qs[qi]; qi++;
            ans[i] = !t.same(na,nb);
        }
        t.merge(a,b);
    }

    rep(i,q) {
        cout << (ans[i]?"Yes":"No") << endl;
    }
    return 0;
}