#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    ll L;
    vector<int> N(2);
    cin >> L >> N[0] >> N[1];
    vector<pair<ll,pair<int,int>>> events;
    rep(i,2) {
        ll t = 0;
        rep(j,N[i]) {
            int v; ll l;
            cin >> v >> l;
            events.emplace_back(t, P(i,v));
            t += l;
        }
    }
    sort(events.begin(), events.end());
    events.emplace_back(L,P(0,0));
    
    vector<int> val(2);
    ll pt = 0;
    ll ans = 0;
    for (auto [t,p] : events) {
        if (val[0] == val[1]) ans += t-pt;
        auto [i,v] = p;
        val[i] = v;
        pt = t;
    }
    
    cout << ans << endl;
    return 0;
}
