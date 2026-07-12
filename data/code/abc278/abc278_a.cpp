#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans;
    for(int i = k; i < n; i++){
        ans.push_back(a[i]);
    }
    if(n <= k) {
        rep(i,n) ans.push_back(0);
    }else {
        rep(i,k) ans.push_back(0);
    }
    rep(i,(int)ans.size()) {
        cout << ans[i] << " \n"[i+1 == (int)ans.size()];
    }
    return 0;
}
