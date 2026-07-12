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
using Grid = vector<string>;

Int H,W,K;
vvl a;

bool fall(){
    bool updated=false;
    rep(j,W){
        queue<Int> holl;
        rrep(i,H){
            if(!holl.empty() && a[i][j] != 0){
                Int h=holl.front(); holl.pop();
                a[h][j]=a[i][j];
                a[i][j]=0;
                updated=true;
            }
            if(a[i][j]==0){
                holl.push(i);
            }
        }
    }
    return updated;
}

Int puyo(){
    Int t=0;
    rep(i,H){
        rep(j,W){
            if(a[i][j]==0)continue;
            Int k;
            for(k = j; k < W && a[i][k] == a[i][j]; k++){
                ;
            }
            if(k-j>=K){
                rep2(l,j,k){
                    t+=a[i][l];
                    a[i][l]=0;
                }
            }
            j=k-1;
        }
    }
    return t;
}

Int solve(){
    Int score=0;
    for(Int t = 1; fall(); t <<= 1){
        score+=t*puyo();
    }
    return score;
}

int main(){
    fio()
    cin>>H>>W>>K;
    a.resize(H,vl(W));
    rep(i,H){
        string s;
        cin>>s;
        rep(j,W){
            a[i][j]=s[j]-'0';
        }
    }
    Int ans=0;
    vvl b=a;
    rep(i,H){
        rep(j,W){
            a[i][j]=0;
            ans=max(ans,solve());
            a=b;
        }
    }
    cout<<ans<<endl;
    return 0 ;
}