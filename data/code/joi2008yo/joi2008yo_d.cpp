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
    
    Int m; cin >> m;
    vector<lP> ps1(m);
    rep(i,m) cin >> ps1[i].first >> ps1[i].second;
    auto [bx,by] = ps1[0];
    Int n; cin >> n;
    vector<lP> ps2(n);
    rep(i,n) cin >> ps2[i].first >> ps2[i].second;
    set<lP> st;
    rep(i,n) {
        auto [x,y] = ps2[i];
        st.insert(lP(x,y));
    }
    rep(i,n) {
        auto [x,y] = ps2[i];
        Int dx = x-bx;
        Int dy = y-by;
        rep(j,m) {
            auto [fx,fy] = ps1[j];
            Int nx = fx+dx;
            Int ny = fy+dy;
            if(!st.count(lP(nx,ny))) {
                break;
            }
            if(j == m-1) {
                cout << dx << " " << dy << endl;
                return 0;
            }
        }
    }
    return 0;
}