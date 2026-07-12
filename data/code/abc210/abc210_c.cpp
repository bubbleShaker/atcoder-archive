#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    
    int ans = 0;
    map<int,int> mp;
    int now = 0;
    rep(i,n) {
        if(mp[c[i]] == 0) now++;
        mp[c[i]]++;
        if(i >= k) {
            mp[c[i-k]]--;
            if(mp[c[i-k]] == 0) now--;
        }
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}
