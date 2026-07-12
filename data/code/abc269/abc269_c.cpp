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

int main(){
    fio()
    Int n;cin>>n;
    Int cnt=0;
    Int tmp=1;
    while(tmp<=n){
        cnt++;
        tmp*=2;
    }
    vector<Int> vecInd;
    for(Int i=0;i<cnt;i++){
        if(n&((Int)1<<i))vecInd.push_back(i);
    }
    // for(Int val:vecInd)cout<<val<<" ";
    // cout<<endl;
    Int sz=vecInd.size();
    
    auto toNum = [&](vector<Int> vec) -> Int{
        Int ret=0;
        Int power=1;
        for(Int i = 0; i < vec.size(); i++){
            ret+=vec[i]*power;
            power*=2;
        }
        return ret;
    };
    vector<Int>vecAns;
    for(Int bit=0;bit<(1<<sz);bit++){
        vector<Int> vecBit(60);
        vector<Int> one;
        rep(i,sz){
            if(bit&(1<<i))one.push_back(i);
        }
        for(Int ind:one){
            vecBit[vecInd[ind]]=1;
        }
        vecAns.push_back(toNum(vecBit));
    }
    sort(all(vecAns));
    for(Int val:vecAns)cout<<val<<endl;
    return 0;
}