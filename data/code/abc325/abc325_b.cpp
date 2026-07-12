#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vd = vector<double>;
using vl = vector<ll>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
//using mint = modint1000000007;
using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    
    Int n; cin >> n;
    vector<pair<Int,Int>> ps(n);
    rep(i,n) {
        Int w,x; cin >> w >> x;
        ps[i].first = x;
        ps[i].second = w;
    }
    sort(all(ps));
    Int ma = 0;
    for(Int i = 0; i <= 23; i++) {
        Int cnt = 0;
        rep(j,n) {
            if(ps[j].first < i) {
                if((i+8)/24 == 0) continue;
                if(ps[j].first <= (i+8)%24) {
                    cnt+=ps[j].second;
                }
            }else if(ps[j].first >= i && ps[j].first <= (i+8)){
                cnt+=ps[j].second;
            }
        }
        chmax(ma,cnt);
    }
    cout << ma << endl;
    return 0 ;
}