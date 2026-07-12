#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<P> p;
    ll base = 0;
    rep(i,n) {
        string s;
        cin >> s;
        int x = 0, a = 0;
        for(char c : s) {
            if(c == 'X') {
                x++;
            }else {
                c -= '0';
                base += x*c;
                a += c;
            }
        }
        p.emplace_back(x,a);
    }
    
    sort(p.begin(), p.end(), [&](P a, P b) {
        return (ll)a.first*b.second > (ll)a.second*b.first;
    });
    
    ll ans = base, xs = 0;
    for(auto [x,a] : p) {
        ans += xs*a;
        xs += x;
    }
    cout << ans << endl;
    return 0;
}