#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<P> pt(m), pa(m);
    rep(i,m) cin >> pt[i].first >> pt[i].second;
    rep(i,m) cin >> pa[i].first >> pa[i].second;
    set<P> st;
    rep(i,m) st.insert(P(pt[i].first, pt[i].second));
    vector<int> p(n);
    rep(i,n) p[i] = i+1;
    
    do{
        set<P> sa;
        vector<P> npa(m);
        map<int,int> mp;
        rep(i,n) mp[i+1] = p[i];
        rep(i,m) {
            auto [c,d] = pa[i];
            if(mp[c] > mp[d]) sa.insert(P(mp[d], mp[c]));
            if(mp[d] > mp[c]) sa.insert(P(mp[c], mp[d]));
            
        }
        if(st == sa) {
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(p.begin(), p.end()));
    cout << "No" << endl;
    return 0;
}