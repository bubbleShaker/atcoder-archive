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
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<P> ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;
    sort(ps.begin(), ps.end());
    vector<int> x(m); 
    rep(i,m) cin >> x[i];
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        l--;
        vector<int> box(x.begin(), x.begin() + l);
        box.insert(box.end(), x.begin() + r, x.end());
        sort(box.begin(), box.end());
        priority_queue<int> q;
        auto p = ps.begin();
        int ans = 0;
        for(auto b : box) {
            while(p != ps.end() && p -> first <= b) q.push(p++->second);
            if(q.size()) {
                ans += q.top();
                q.pop();
            }
        }
        cout << ans << endl;
    }
    return 0;
}