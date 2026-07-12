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
using mint = modint1000000007;
//using mint = modint998244353;
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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    
    Int n,k; cin >> n >> k;
    Int R,S,P; cin >> R >> S >> P;
    string t; cin >> t;
    map<char,Int> winp;
    map<char,Int> winc;
    winp['r'] = P;
    winp['s'] = R;
    winp['p'] = S;
    winc['r'] = 'p';
    winc['s'] = 'r';
    winc['p'] = 's';
    Int ans = 0;
    vector<char> visited(n,'z');
    rep(i,k) {
        for(Int j = i; j < n; j+=k) {
            if(j == i) {
                ans+=winp[t[j]];
                visited[j]=winc[t[j]];
            }else {
                if(winc[t[j]]==visited[j-k]) {
                    set<char> st;
                    string base = "rsp";
                    st.insert(winc[t[j]]);
                    if(j+k < n) {
                        st.insert(winc[t[j+k]]);
                    }
                    rep(k,3) {
                        if(st.count(base[k])) continue;
                        else {
                            visited[j] = base[k];
                        }
                    }
                }
                else {
                    ans+=winp[t[j]];
                    visited[j]=winc[t[j]];
                }
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}