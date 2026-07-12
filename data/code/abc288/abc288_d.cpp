#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    vector s(k, vector<ll>(n+1));
    rep(i,n) s[i%k][i+1] = a[i];
    rep(i,k)rep(j,n) s[i][j+1] += s[i][j];
    
    int q;
    cin >> q;
    rep(qi,q) {
        int l, r;
        cin >> l >> r;
        --l;
        vector<ll> ns(k);
        rep(i,k) ns[i] = s[i][r]-s[i][l];
        sort(ns.begin(), ns.end());
        if(ns[0] == ns.back()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}