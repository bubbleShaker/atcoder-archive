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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;
#define FACSIZE 1048576

long long power(long long a, long long b) {
    long long x = 1, y = a;
    while(b>0) {
        if(b&1ll) {
            x=(x*y)%MOD;
        }
        y=(y*y)%MOD;
        b>>=1;
    }
    return x%MOD;
}

long long modular_inverse(long long n) {
    return power(n,MOD-2);
}

int main(){
    fio()
    long long n; cin >> n;
    long long invn = modular_inverse(n);
    long long p = invn,res=0;
    for(long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        res += p*a; res%=MOD;
        p+=p*invn; p%=MOD;
    }
    cout << res << endl;
    return 0 ;
}