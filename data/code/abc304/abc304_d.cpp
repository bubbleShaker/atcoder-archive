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
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
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
    Int w,h;cin>>w>>h;
    Int n;cin>>n;
    vector<lP> ps;
    rep(i,n) {
        Int p,q;cin>>p>>q;
        ps.emplace_back(p,q);
    }
    Int A;cin>>A;
    vl a(A);
    rep(i,A)cin>>a[i];
    Int B;cin>>B;
    vl b(B);
    rep(i,B)cin>>b[i];
    map<pair<Int,Int>,Int> mp;
    for(auto [x,y] : ps) {
        Int xi = lower_bound(all(a),x)-a.begin();
        Int yi = lower_bound(all(b),y)-b.begin();
        mp[lP(xi,yi)]++;
    }
    set<Int> st;
    for(auto [pairVer,cnt] : mp) {
        st.insert(cnt);
    }
    if(mp.size() < (A+1)*(B+1)) st.insert(0);
    cout << *begin(st) << " " <<  *rbegin(st) << endl;
    return 0 ;
}