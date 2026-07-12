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
// const vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
const ll MOD = 1000000007;
// const ll MOD = 998244353;

vector<Int> permutation;
void dfs(Int depth, Int size, Int min, Int max,vvl& pvec) {
    if (depth == size) {
        pvec.push_back(permutation);
    }
    else {
        for (Int i = min; i <= max; i++) {
            permutation[depth] = i;
            dfs(depth+1, size, min, max,pvec);
        }
    }
}

int main(){
    fio();
    Int n;cin>>n;
    Int now=0;
    set<Int> ansSet;
    vl vec;
    while(ansSet.size()<=335){
        now*=10;
        now+=1;
        vec.push_back(now);
        vvl pvec;
        permutation.resize(3);
        dfs(0,3,1,vec.size(),pvec);
        // cout<<"vecsize:"<<vec.size()<<endl;
        // rep(i,vec.size()){
        //     cout<<vec[i]<<" ";
        // }
        // cout<<endl;
        for(vl p:pvec){
            Int sum=0;
            rep(i,p.size()){
                sum+=vec[p[i]-1];
                // cout<<p[i]<<" ";
            }
            // cout<<endl;
            ansSet.insert(sum);
        }
    }
    vl tvec;
    for(Int val:ansSet)tvec.push_back(val);
    cout<<tvec[n-1]<<endl;
    return 0;
}