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

ll epow(ll a, ll b) {
    ll t = 1;
    rep(i,b) {
        t *= a;
    }
    return t;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    auto pf = [](ll n) {
        vector<pair<ll,ll>> res;
        res.emplace_back(1,1);
        for(ll a = 2; a*a <= n; a++) {
            if(n%a != 0) continue;
            ll ex = 0;
            
            while(n%a == 0) {
                n /= a;
                ex++;
            }
            
            res.emplace_back(a,ex);
        }
        
        if(n != 1) res.emplace_back(n,1);
        return res;
    };
    
    rep(i,t) {
        int c; cin >> c;
        vector<pair<ll,ll>> sb = pf(c);
        ll sum = 0;
        for(auto [a,ex] : sb) {
            ll val = epow(a,ex);
            sum += val;
        }
        if(sum > c) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}