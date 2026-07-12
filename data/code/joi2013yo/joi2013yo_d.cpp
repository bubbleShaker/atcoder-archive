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
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
// vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;

int main(){
    fio()
    int n,d;
    cin>>d>>n;
    int t[d];
    for(int i=0;i<d;i++)cin>>t[i];
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
    int dp[d+1][101];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        if(a[i]<=t[0]&&t[0]<=b[i])
          dp[1][c[i]]=0;
    }
    for(int i=1;i<d;i++){
        for(int j=0;j<101;j++){
            if(dp[i][j]<0)continue;
            for(int k=0;k<n;k++){
                if(a[k]<=t[i]&&t[i]<=b[k]){
                    dp[i+1][c[k]]=max(dp[i+1][c[k]],dp[i][j]+abs(j-c[k]));
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<101;i++)
      if(~dp[d][i]) ans=max(ans,dp[d][i]);
    cout<<ans<<endl;
    return 0;
}