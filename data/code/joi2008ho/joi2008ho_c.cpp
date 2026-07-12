#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    rep(i,n) cin >> p[i];
    vector<int> v;
    rep(i,n+1)for(int j = i; j < n+1; j++) {
        v.push_back(p[i]+p[j]);
    }
    sort(v.begin(), v.end());
    int vs = v.size();
    int ans = 0;
    rep(i,vs) {
        int nokori = m-v[i];
        int mai = upper_bound(v.begin(), v.end(), nokori)-v.begin();
        mai--;
        if(v[i] > m || v[mai] > m) continue;
        ans = max(ans, v[i]+v[mai]);
    }
    cout << ans << endl;
    return 0;
}