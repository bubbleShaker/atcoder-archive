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
#define REP(i,x,y) for(Int i = x; i <= (Int)y; ++i)
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

const int max_n = 100005;
const int max_m = 100005;
int n,m;
int p[max_m];
long long a,b,c;
long long sum[max_m],ans;

int main(){
    fio()
    cin>>n>>m;
    REP(i,1,m)cin>>p[i];
    REP(i,1,m-1) {
        if(p[i]<p[i+1]){
            sum[p[i]]++;
            sum[p[i+1]]--;
        }else{
            sum[p[i]]--;
            sum[p[i+1]]++;
        }
    }
    REP(i,1,n-1){
        sum[i]+=sum[i-1];
        cin>>a>>b>>c;
        ans+=min(a*sum[i],b*sum[i]+c);
    }
    cout<<ans<<endl;
    return 0 ;
}