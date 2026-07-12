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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

Int H,W,K;
string S[10];

Int cnt[11];
Int solve(vector<Int> grp) {
    Int res=0;
    Int x=0;
    
    while(x<W) {
        rep(c,11) cnt[c]=0;
        
        Int nxt=x;
        REP(xx,x,W){
            bool ng=false;
            REP(y,0,H)if(S[y][xx]=='1'){
                cnt[grp[y]]++;
                if(K<cnt[grp[y]]) ng=true;
            }
            if(ng)break;
            chmax(nxt,xx+1);
        }
        if(nxt==x)return INF;
        x=nxt;
        res++;
    }
    return res-1;
}

int main(){
    fio()
    cin>>H>>W>>K;
    REP(y,0,H)cin>>S[y];
    
    Int ans=INF;
    rep(Div,1<<(H-1)){
        vector<Int> grp;
        Int g=1,cnt=0;
        rep(i,H-1){
            grp.push_back(g);
            if(Div&(1<<i))g++,cnt++;
        }
        grp.push_back(g);
        chmin(ans,solve(grp)+cnt);
    }
    cout<<ans<<endl;
    return 0 ;
}