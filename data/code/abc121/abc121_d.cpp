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
    
    Int a, b;
    cin >> a >> b;
    
    auto f = [&](ll _, ll y) -> Int {
        if(y%2) {
            y++;
            y /= 2;
            if(y%2 == 0) return 0;
            else return 1;
        }else {
            Int t = y;
            t /= 2;
            if(t%2 == 0) return y^0;
            else return y^1;
        }
    };
    Int ans = f(0,a-1)^f(0,b);
    cout << ans << endl;
    return 0;
}