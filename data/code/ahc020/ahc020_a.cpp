#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n), y(n);
    vector<vector<int>> e(m);
    vector<int> w(m);
    vector<int> a(k), b(k);
    rep(i,n) cin >> x[i] >> y[i];
    rep(i,m){
        int t1, t2;
        cin >> t1 >> t2;
        e[t1].push_back(t2);
        e[t2].push_back(t1);
        cin >> w[i];
    }
    rep(i,k) cin >> a[i] >> b[i];
    
    rep(i,n){
        cout << 2500 << " \n"[i+1 == n];
    }
    rep(i,m){
        cout << 1 << " \n"[i+1 == n];
    }
    return 0;
}
