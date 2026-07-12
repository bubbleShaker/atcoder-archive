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
//const vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;
#define MAX 1050

int main(){
    fio()
    int N;
    cin>>N;
    
    vector<string> S(5);
    for(int i=0;i<5;i++){
        cin>>S[i];
    }
    
    int R=0;
    int B=1;
    int W=2;
    
    vector<vector<int>> dp(N,vector<int>(3,INF));
    vector<vector<int>> cnt(N,vector<int>(3,5));
    
    for(int i=0;i<5;i++){
        for(int j=0;j<N;j++){
            int k;
            if(S[i][j]=='#')continue;
            if(S[i][j]=='R')k=0;
            if(S[i][j]=='B')k=1;
            if(S[i][j]=='W')k=2;
            cnt[j][k]--;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            if(i==0){
                dp[i][j]=cnt[i][j];
            }
            else{
                for(int k=0;k<3;k++){
                    if(j==k)continue;
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+cnt[i][j]);
                }
            }
        }
    }
    cout<<min({dp[N-1][0],dp[N-1][1],dp[N-1][2]})<<endl;
    return 0;
}