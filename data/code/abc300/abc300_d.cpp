#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
// using mint = modint998244353;
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

#define MAXP 300005

vector<Int> sieve(){
    vector<Int>res;
    vector<Int>mem(MAXP,0);
    for(Int i=2;i<MAXP;i++){
        if(mem[i])continue;
        res.push_back(i);
        for(Int j=i;j<MAXP;j+=i)mem[j]=1;
    }
    return res;
}

int main(){
    fio()
    vector<Int>p=sieve();
    Int n;
    cin>>n;
    Int sz=p.size();
    Int res=0;
    for(Int i=0;i<sz;i++){
        Int k=sz-1;
        for(Int j=i+1;j<k && j<sz;j++){
            while(j<k){
                Int v=p[i]*p[i]*p[j];
                if(v>n){ k--;continue; }
                v*=p[k];
                if(v>n){ k--;continue; }
                v*=p[k];
                if(v>n){ k--;continue; }
                break;
            }
            res+=(k-j);
        }
    }
    cout<<res<<endl;
    return 0 ;
}