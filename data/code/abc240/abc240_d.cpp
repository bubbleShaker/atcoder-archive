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
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<P> dq;
    rep(i,n) {
        if(dq.empty()) {
            dq.emplace_back(a[i],1);
            int ans = 0;
            for(auto [v,c] : dq) {
                ans += c;
            }
            cout << ans << endl;
            continue;
        }
        auto& [v,c] = dq.back();
        if(v == a[i]) {
            c++;
            if(v == c) dq.pop_back();
        }else {
            dq.emplace_back(a[i],1);
        }
        int ans = 0;
        for(auto [v,c] : dq) {
            ans += c;
        }
        cout << ans << endl;
    }
    
    return 0;
}