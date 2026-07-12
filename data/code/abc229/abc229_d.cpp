#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using lT = tuple<int,ll,ll>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector<int> ind;
    ind.push_back(-1);
    rep(i,n) {
        if(s[i] == '.') ind.push_back(i);
    }
    ind.push_back(n);
    int ans = 0;
    int nn = ind.size();
    for(int i = 0; i <= nn-1; i++) {
        if(i+k >= nn) {
            int sum = ind[nn-1]-1-(ind[i-1]);
            ans = max(ans,sum);
            continue;
        }
        int sum = ind[i+k]-1-(ind[i-1]);
        ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}