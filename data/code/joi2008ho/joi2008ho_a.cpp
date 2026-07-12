#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    Int n;
    cin >> n;
    vector<Int> c(n);
    rep(i,n) cin >> c[i];
    deque<lP> q;
    q.emplace_back(c[0],1);
    
    for(Int i = 1; i < n; i++) {
        auto& [color,cnt] = q.back();
        if((i+1)%2) {
            if(c[i] == color) cnt++;
            else {
                q.emplace_back(c[i],1);
            }
        }
        if((i+1)%2 == 0) {
            if(c[i] == color) {
                cnt++;
            }else {
                cnt++;
                color = (1-color);
            }
        }
        if(q.size() <= 1) continue; 
        auto [nc,ncnt] = q.back();
        q.pop_back();
        auto [pc,pcnt] = q.back();
        if(nc == pc) {
            q.pop_back();
            q.emplace_back(nc,ncnt+pcnt);
        }else q.emplace_back(nc,ncnt);
    }
    Int ans = 0;
    for(auto [color,cnt] : q) {
        if(color == 0) ans += cnt;
    }
    cout << ans << endl;
    return 0;
}