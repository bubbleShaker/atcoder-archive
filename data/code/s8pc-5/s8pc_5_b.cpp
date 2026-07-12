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

Int N,M;
double x[205],y[205],r[205];

double dist(Int i,Int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
bool check(double R) {
    for(Int i = N+1; i <= N+M; i++) r[i]=R;
    for(Int i = 1; i <= N+M; i++) {
        for(Int j = 1; j <= N+M; j++) {
            if(i>=j)continue;
            if(dist(i,j) < r[i]+r[j]) return false;
        }
    }
    return true;
}

int main(){
    fio()
    cin>>N>>M;
    for(Int i = 1; i <= N; i++)cin>>x[i]>>y[i]>>r[i];
    for(Int i = N+1; i <= N+M; i++)cin>>x[i]>>y[i];
    
    double minR=500;
    for(Int i = 1; i <= N; i++) minR=min(minR,r[i]);
    
    double ub = minR, lb = 0, mid;
    for(Int i = 0; i < 100; i++) {
        mid=(ub+lb)*0.5;
        if(check(mid))lb=mid;
        else ub = mid;
    }
    printf("%.11f\n",(lb+ub)/2);
    return 0 ;
}