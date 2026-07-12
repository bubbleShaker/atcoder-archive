#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 1; i <= n; i++) v[i-1] = i;
    map<int,int> mp;
    rep(i,n) mp[v[i]] = i;
    rep(i,q) {
        int x;
        cin >> x;
        if(mp[x] != n-1) {
            int li = mp[x];
            int ri = li+1;
            mp[v[ri]]--;
            mp[x]++;
            swap(v[li], v[ri]);
        }else {
            int ri = mp[x];
            int li = ri-1;
            mp[v[li]]++;
            mp[x]--;
            swap(v[li],v[ri]);
        }
    }
    rep(i,n) cout << v[i] << " \n"[i+1 == n];
    return 0;
}
