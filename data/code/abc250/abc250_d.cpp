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
//const ll MOD = 1000000007;
const ll MOD = 998244353;

//計算量O(NloglogN)
vector<bool> Eratosthenes(Int n) {
    vector<bool> isprime(n+1,true);
    //1はあらかじめふるい落とす
    isprime[1] = false;
    //ふるい
    for(Int p = 2; p <= n; p++) {
        //すでに合成数ならスキップ
        if(!isprime[p]) continue;
        //p以外のpの倍数から素数ラベルを剥奪
        for(Int q = p*2; q <= n; q+=p) {
            isprime[q] = false;
        } 
    }
    //1以上n以下の整数が素数かどうか
    return isprime;
}

int main(){
    fio()
    Int n;cin>>n;
    Int MA=(Int)cbrt((double)n);
    vector<bool> isprime=Eratosthenes(MA);
    vl srcVec;
    for(Int i=1;i<=MA;i++){
        if(isprime[i])srcVec.push_back(i);
    }
    Int ans=0;
    Int sz=srcVec.size();
    for(Int i=sz-1;i>=0;i--){
        Int q3=srcVec[i]*srcVec[i]*srcVec[i];
        srcVec.erase(find(all(srcVec),srcVec[i]));
        if(srcVec.size()==0)break;
        Int src=n/q3;
        Int li=lower_bound(all(srcVec),src)-srcVec.begin();
        if(li==srcVec.size())li--;
        else if(srcVec[li]!=src)li--;
        ans+=li+1;
    }
    cout<<ans<<endl;
    return 0;
}