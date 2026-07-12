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
#define REP(i,x,y) for(Int i = x; i <= (Int)y; ++i)
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

int main(){
    fio()
    Int n,m,k;cin>>n>>m>>k;
    vl a(n),b(m);
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];
    vl ruisekiwaA(n+1),ruisekiwaB(m+1);
    rep(i,n)ruisekiwaA[i+1]+=ruisekiwaA[i]+a[i];
    rep(i,m)ruisekiwaB[i+1]+=ruisekiwaB[i]+b[i];
    Int ans = 0;
    rep(i,n+1){
        if(k-ruisekiwaA[i]<0)continue;
        Int bi = upper_bound(all(ruisekiwaB),k-ruisekiwaA[i])-ruisekiwaB.begin()-1;
        chmax(ans,i+bi);
    }
    cout<<ans<<endl;
    return 0 ;
}