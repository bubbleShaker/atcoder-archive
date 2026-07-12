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
    Int n,q;cin>>n>>q;
    vector<vector<lP>> g(n+1);

    auto dfs1 = [&](auto dfs1,Int from) -> Int {
        Int ret;
        for(auto [to,val]:g[from]){
            if(val==1){
                return ret=dfs1(dfs1,to);
            }
        }
        return ret=from;
    };

    auto dfs2 = [&](auto dfs2,Int from,vl &ansVec) -> void {
        ansVec.push_back(from);
        for(auto [to,val]:g[from]){
            if(val==-1){
                dfs2(dfs2,to,ansVec);
            }
        }
        return;
    };

    while(q--){
        Int val;cin>>val;
        if(val==1){//1→先頭へ、-1→末尾へ
            Int x,y;cin>>x>>y;x--;y--;
            g[y].emplace_back(x,1);
            g[x].emplace_back(y,-1);
        }
        if(val==2){
            Int x,y;cin>>x>>y;x--;y--;
            g[y].erase(find(all(g[y]),lP(x,1)));
            g[x].erase(find(all(g[x]),lP(y,-1)));
        }
        if(val==3){
            Int x;cin>>x;x--;
            Int from=dfs1(dfs1,x);
            vl ansVec;
            dfs2(dfs2,from,ansVec);
            cout<<ansVec.size()<<" ";
            rep(i,ansVec.size()){
                cout<<ansVec[i]+1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}