#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    ll k;
    cin >> k;
    vector<pair<ll,ll>> ps;
    
    auto pf = [](ll n) {
        vector<pair<ll,ll>> res;
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
    
    auto fun = [&](ll p, ll n){
        ll res = 0;
        while(n != 0) {
            n /= p;
            res += n;
        }
        return res;
    };
    
    auto ffun = [&](ll n) {
        for(auto [p,pe] : ps) {
            ll res = fun(p,n);
            if(pe > res) {
                return false;
            }
        }
        return true;
    };
    
    ps = pf(k);
    
    ll l = 1, r = 1000000000000;
    while(r-l > 1) {
        ll cen = (l+r)/2;
        if(ffun(cen)) r = cen;
        else l = cen;
    }
    cout << r << endl;
    return 0;
}
