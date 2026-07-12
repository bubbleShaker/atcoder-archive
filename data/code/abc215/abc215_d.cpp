#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vl = vector<ll>;
using vvl = vector<vl>;
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
#define rep2(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define rrep(i,n) for (Int i=n;i>=0;i--)
#define rrep2(i,a,b) for (Int i=a;i>=b;i--)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
// const vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;

int main(){
    fio()
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
    Int n,m;cin>>n>>m;
    vl a(n);
    rep(i,n){
        cin>>a[i];
    }
    vector<bool> isChecked(100010);
    rep(i,n){
        vector<lP> ps;
        ps=pf(a[i]);
        for(auto [val,ex]:ps){
            if(isChecked[val])continue;
            for(Int j=val;j<=m;j+=val){
                isChecked[j]=true;
            }
        }
    }
    vl ans;
    for(Int i=1;i<=m;i++){
        if(!isChecked[i])ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()){
        cout<<ans[i]<<endl;
    }
    return 0;
}