#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    
    auto f = [&](vector<int> x) {
        rep(i,k) x[i]++;
        cout << '?';
        rep(i,k) cout << ' ' << x[i];
        cout << endl;
        int res;
        cin >> res;
        return res;
    };
    
    vector<int> b(k+1);
    int t = 0;
    rep(i,k+1) {
        vector<int> x;
        rep(j,k+1) if(i != j) x.push_back(j);
        b[i] = f(x);
        t ^= b[i];
    }
    rep(i,k+1) a[i] = b[i]^t;
    
    t = 0;
    rep(i,k-1) t ^= a[i];
    for(int i = k+1; i < n; i++) {
        vector<int> x;
        rep(j,k-1) x.push_back(j);
        x.push_back(i);
        a[i] = t^f(x);
    }
    
    cout << '!';
    rep(i,n) cout << ' ' << a[i];
    cout << endl;
    return 0;
}