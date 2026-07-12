#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
//using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio();
    
    Int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    auto pf = [](ll n) {
        vector<pair<ll,ll>> res;
        for(ll a = 2; a*a <= n; a++) {
            if(n%a != 0) continue;
            ll ex = 0;
            
            while(n%a == 0) {
                n /= a;
                ex++;
            }
            
            res.emplace_back(a,ex);
        }
        
        if(n != 1) res.emplace_back(n,1);
        return res;
    };
    
    for(Int i = a; i <= b; i++) {
        bool fl = false;
        for(Int j = c; j <= d; j++) {
            Int now = i+j;
            vector<pair<ll,ll>> v = pf(now);
            if(v.size() == 1) {
                if(v[0].second == 1) fl = true;
            }
        }
        if(!fl) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0 ;
}