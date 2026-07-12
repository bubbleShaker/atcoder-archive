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
    dsu uf(n);
    int ans1 = 0;
    rep(i,m) {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        if(uf.same(a,c)) ans1++;
        uf.merge(a,c);
    }
    set<int> st;
    rep(i,n){
        int l = uf.leader(i);
        if(!st.count(l)) st.insert(l);
    }
    cout << ans1 << " " << (int)st.size() - ans1 << endl;
    return 0;
}
