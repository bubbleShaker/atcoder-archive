#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    ll a, b;
    cin >> a >> b;
    ll l = 0, r = 1000000000000000000;
    auto f = [&](ll cen) {
        return (double)a/(double)sqrt(cen+1)+(double)b*(double)cen;
    };
    while(r-l > 2) {
        ll cen1 = (l+r)/2;
        ll cen2 = cen1 + 1;
        if(f(cen1) > f(cen2)) l = cen1;
        else r = cen2;
    }
    double ans = min({f(l), f(l+1), f(r)});
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}
