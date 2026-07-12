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
#define pb(a) push_back(a)
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
//#define rep(i,x,y) for(Int i = x; i < (Int)y; ++i)
//#define rep(i,x,y) for(Int i = x; i <= (Int)y; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    Int n; cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    vl sumVec;
    rep(i,n-1) {
       if(i%2) {
           sumVec.push_back(a[i+1]-a[i]);
       } 
    }
    vl ruisekiwa(sumVec.size()+1);
    rep(i,sumVec.size()) {
        ruisekiwa[i+1] += ruisekiwa[i]+sumVec[i];
    }
    Int q; cin >> q;
    while(q--) {
        Int l, r; cin >> l >> r;
        Int li = lower_bound(all(a),l)-a.begin();
        Int ri = lower_bound(all(a),r)-a.begin();
        Int ans = 0;
        if(li%2 == 0) {
            ans+=a[li]-l;
            li++;
        }
        if(ri%2 == 0) {
            ans+=abs(a[ri-1]-r);
            ri--;
        }
        ans+=ruisekiwa[ri/2]-ruisekiwa[li/2];
        cout << ans << endl;
    }
    return 0 ;
}