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
//using mint = modint1000000007;
using mint = modint998244353;
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
    
    Int n,m; cin >> n >> m;
    vector<vl> g(n);
    rep(i,m) {
        Int x,y; cin >> x >> y; x--;y--;
        g[x].push_back(y);
    }
    vl ans(n,-1);
    
    auto f = [&](auto f,Int v) -> Int { //vを始点とした時の最長パスの長さ
        Int ma = 0;
        for(auto to : g[v]) {
            if(ans[to] != -1) chmax(ma,ans[to]+1);
            else chmax(ma,f(f,to)+1);
        }
        ans[v] = ma;
        return ma;
    };
    
    rep(i,n) {
        if(ans[i] == -1) f(f,i);
    }
    Int ma = 0;
    rep(i,n) chmax(ma,ans[i]);
    cout << ma << endl;
    return 0 ;
}