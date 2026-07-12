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
#define rrep(i,n) for (Int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (Int i = (a)-1;i>=b;i--)
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
//const vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;

vector<Int> combination;
vvl vecVec; 
void dfs(Int depth, Int siz, Int min, Int max) {
    if (depth == siz) {
        vl tmpVec;
        for (Int i = 0; i < depth; i++) {
            tmpVec.push_back(combination[i]);
        }
        vecVec.push_back(tmpVec);
    }
    else {
        for (Int i = min; i <= max; i++) {
            combination[depth] = i;
            // i を i+1 に変更した
            dfs(depth+1, siz, i+1, max);
        }
    }
}

int main(){
    fio()
    Int n, m, k;
    cin >> n >> m >> k;
    // priority_queue<lT,vector<lT>,greater<lT>> q;
    vector<tuple<Int,Int,Int>> edge;
    rep(i,m) {
        Int s, t, w;
        cin >> s >> t >> w; s--; t--; w%=k;
        edge.emplace_back(s,t,w);
    }
    combination.resize(n-1);
    dfs(0,n-1,0,m-1);
    Int mi = INFL;
    for(vl nowVec:vecVec){
        dsu uf(n);
        Int ans = 0;
        for(Int ind:nowVec) {
            auto [u,v,cost] = edge[ind];
    
            if(uf.same(u,v)) continue;
            ans += cost;
            ans%=k;
            uf.merge(u,v);
        }
        set<Int> lst;
        rep(i,n){
            lst.insert(uf.leader(i));
        }
        if(lst.size()==1)chmin(mi,ans);
    }
    cout << mi << endl;
    return 0;
}