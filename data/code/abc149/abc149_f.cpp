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
//using P = pair<int,int>;
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

int N;
vector<int> E[201010];
int C[201010];
const ll mo = 1000000007;
ll ret;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur,int pre) {
    C[cur] = 1;
    vector<ll> B;
    fore(e,E[cur]) if(e!=pre) {
        B.push_back(dfs(e,cur));
        C[cur]+=B.back();
    }
    if(C[cur]<N) B.push_back(N-C[cur]);
    
    ll P[3]={(mo+1)/2,0,0};
    fore(b,B) {
        ll w = modpow((mo+1)/2,b);
        b=(1+mo-w)%mo;
        ll Q[3]={};
        Q[0]=P[0]*w%mo;
        Q[1]=(P[1]*w+P[0]*b)%mo;
        Q[2]=(P[2]+P[1]*b)%mo;
        swap(P,Q);
    }
    ret+=P[2];
    return C[cur];
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin >> N;
    rep(i,N-1) {
        cin >> x >> y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0,-1);
    cout << ret%mo << endl;
}
 
int main(){
    fio()
    solve();
    return 0 ;
}