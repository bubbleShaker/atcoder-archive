#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<pair<ll,int>> ps(n);
    rep(i,n) {
        int f;
        ll s;
        cin >> f >> s;
        ps[i].first = s;
        ps[i].second = f;
    }
    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());
    
    ll oisisa = ps[0].first;
    int ff = ps[0].second;
    auto [ts, tf] = ps[1];
    ll tmp = 0;
    if(ff != tf) {
        oisisa += ts;
        cout << oisisa << endl;
        return 0;
    }else {
        tmp = oisisa;
        ll ns = ts/2;
        oisisa += ns;
    }
    
    for(int i = 1; i < n; i++) {
        auto [ts, tf] = ps[i];
        if(ff != tf) {
            tmp += ts;
            break;
        }
    }
    oisisa = max(oisisa, tmp);
    cout << oisisa << endl;
    return 0;
}
