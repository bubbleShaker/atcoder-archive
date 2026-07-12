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
    int n,k;cin>>n>>k;
    int d[101]={};
    int i,j,l,m;
    int a,b;
    for(i=0;i<n;i++){
        cin>>a>>b;
        d[a-1]=b;
    }
    int dp[101][4][4]={{{}}};
    if(d[0]!=0){
        dp[0][0][d[0]]=1;
    }else{
        dp[0][0][1]=1;
        dp[0][0][2]=1;
        dp[0][0][3]=1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<4;j++){
            for(l=1;l<4;l++){
                if(d[i]!=0){
                    if(!(j==l&&l==d[i]))
                    dp[i][l][d[i]]+=dp[i-1][j][l]%10000;
                }else{
                    for(m=1;m<4;m++){
                        if(j==l&&l==m)continue;
                        dp[i][l][m]+=dp[i-1][j][l]%10000;
                    }
                }
            }
        }
    }
    int o=0;
    for(j=0;j<4;j++){
        for(l=1;l<4;l++){
            o+=dp[n-1][j][l];
        }
    }
    cout<<o%10000<<endl;
    return 0;
}