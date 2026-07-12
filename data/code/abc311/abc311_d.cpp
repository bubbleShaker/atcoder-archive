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
using fT = tuple<ll,ll,ll,ll>;
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

int main(){
    fio()
    Int n,m; cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    set<lP> st;
    queue<lP> q;
    q.emplace(1,1);
    st.insert(lP(1,1));
    set<lP> nodeSet;
    nodeSet.insert(lP(1,1));
    
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        
        rep(i,4) {
            Int nx = x, ny = y;
            bool fl = true;
            while(fl) {
                nx += dx[i], ny += dy[i];
                if(s[nx][ny] == '.') {
                    st.insert(lP(nx,ny));
                    continue;
                }
                if(s[nx][ny] == '#') {
                    nx-=dx[i];
                    ny-=dy[i];
                    if(!nodeSet.count(lP(nx,ny))) {
                        nodeSet.insert(lP(nx,ny));
                        q.emplace(nx,ny);
                        st.insert(lP(nx,ny));
                    }
                    fl = false;;
                }
            }
        }
    }
    cout << st.size() << endl;
    return 0 ;
}