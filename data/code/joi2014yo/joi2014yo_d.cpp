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
const vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
// const vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
//const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int MOD = 10007;

template <class T>
T add_mod(T &a,const T &b){
    a+=b;
    a%=MOD;
    return a;
}

Int N;
string S;
Int dp[1<<3][1100];
Int resp[1100];

int main(){
    fio()
    cin>>N>>S;
    rep(i,N){
        if(S[i]=='J'){
            resp[i+1]=1<<0;
        }else if(S[i]=='O'){
            resp[i+1]=1<<1;
        }else if(S[i]=='I'){
            resp[i+1]=1<<2;
        }
    }
    dp[1][0]=1;
    rep(i,N){
        rep(now,1<<3){
            rep(next,1<<3){
                if(now&next){
                    if(next&resp[i+1]){
                        add_mod(dp[next][i+1],dp[now][i]);
                    }
                }
            }
        }
    }
    
    Int ans=0;
    rep(now,1<<3)add_mod(ans,dp[now][N]);
    cout<<ans<<endl;
    return 0;
}