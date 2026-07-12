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
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;

int main(){
    fio()
    Int n,m;cin>>n>>m;
    vl a(m),b(m);
    rep(i,m){
        cin>>a[i];
        a[i]--;
    }
    rep(i,m){
        cin>>b[i];
        b[i]--;
    }
    vvl g(n);
    rep(i,m){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vl visitedTurn(n,-1);
    
    auto dfs = [&](auto dfs,Int from,Int turn=0) -> void{
        if(visitedTurn[from]!=-1){
            if((turn-visitedTurn[from])%2){
                cout<<"No"<<endl;
                exit(0);
            }
            return;
        }
        visitedTurn[from]=turn;
        for(Int to:g[from]){
            dfs(dfs,to,turn+1);
        }
    };
    
    rep(i,n){
        if(visitedTurn[i]==-1) dfs(dfs,i);
    }
    cout<<"Yes"<<endl;
    return 0;
    // dsu uf(n);
    // rep(i,m){
    //     if(a[i]==b[i]){
    //         cout<<"No"<<endl;
    //         return 0;
    //     }
    // }
    // rep(i,m){
    //     uf.merge(a[i],b[i]);
    // }
    // map<Int,Int> ufMap;
    // rep(i,n){
    //     ufMap[uf.leader(i)]++;
    // }
    // for(auto [leader,cnt]:ufMap){
    //     if(cnt%2){
    //         cout<<"No"<<endl;
    //         return 0;
    //     }
    // }
    // cout<<"Yes"<<endl;
    return 0;
}