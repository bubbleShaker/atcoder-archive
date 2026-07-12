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
    vector<lP> ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;
    stable_sort(ps.begin(), ps.end(), [](lP a, lP b){
        return 2*a.first+a.second >= 2*b.first+b.second;
    });
    ll asum = 0;
    ll tsum = 0;
    rep(i,n) asum += ps[i].first;
    int ans = 0;
    rep(i,n) {
        if(tsum - asum > 0) break;
        tsum += ps[i].first+ps[i].second;
        asum -= ps[i].first;
        ans++;
    }
    cout << ans << endl;
    return 0;
}