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
    
    Int n, m; cin >> n >> m;
    vector<Int> p(n);
    vector<set<Int>> f(n);
    rep(i,n) {
        cin >> p[i];
        Int c; cin >> c;
        Int tmpF;
        rep(j,c) {
            cin >> tmpF;
            f[i].insert(tmpF);
        }
    }
    Int ans = 0;
    rep(i,n)rep(j,n) {
        if(p[i]>p[j]) {
            bool fl = false;
            for(Int func : f[i]) {
                if(!f[j].count(func)) {
                    fl = true;
                    break;
                }
            }
            if(fl) continue;
            ans++;
        }else if(p[i]==p[j]) {
            bool fl = false;
            for(Int func : f[i]) {
                if(!f[j].count(func)) {
                    fl = true;
                    break;
                }
            }
            if(fl) continue;
            for(Int func : f[j]) {
                if(!f[i].count(func)) {
                    fl = true;
                    break;
                }
            }
            if(fl) ans++;
        }
    }
    if(ans>=1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0 ;
}