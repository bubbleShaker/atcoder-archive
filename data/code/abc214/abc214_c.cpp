#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    rep(i,n*2) {
        t[(i+1)%n] = min(t[(i+1)%n], t[i%n]+s[i%n]);
    }
    rep(i,n) cout << t[i] << endl;
    return 0;
}
