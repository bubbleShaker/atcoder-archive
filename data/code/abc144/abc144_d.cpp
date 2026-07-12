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

const long double PI = (acos(-1));
const long double EPS = 0.0000000001;

long double a,b,x;

void input() {
    cin >> a >> b >> x;
}

long double f(long double a, long double b, long double theta) {
    if(theta > PI/2.0-EPS) {
        return 0.0;
    }
    long double ret;
    if(a*tan(theta) <= b) {
        ret = a*a*b-a*a*a*tan(theta)/2.0;
    }else {
        ret=b*b/tan(theta)*a/2.0;
    }
    return ret;
}

void solve() {
    input();
    long double ok = PI/2.0;
    long double ng = 0.0;
    for(int _ = 1; _ <= 100000; _++) {
        long double mid = (ok + ng) / 2.0;
        if(f(a,b,mid) < x) ok = mid;
        else ng = mid;
    }
    sp(10)
    cout << ok/PI*180<<endl;
}

int main(){
    fio()
    solve();
    return 0 ;
}