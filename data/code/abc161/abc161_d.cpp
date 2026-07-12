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

int main(){
    fio()
    Int k;
    cin>>k;
    set<Int> ansSet;
    vl vec;
    
    auto toVal = [&](vl v){
        Int ret=0;
        rep(i,v.size()){
            ret=ret*10+v[i];
        }
        return ret;
    };
    
    auto dfs = [&](auto dfs,Int from,Int keta){
        if(vec.size()==keta){
            Int val = toVal(vec);
            ansSet.insert(val);
            return ;
        }
        
        if(from-1>=0){
            vec.push_back(from-1);
            dfs(dfs,from-1,keta);
            vec.pop_back();
        }
        vec.push_back(from);
        dfs(dfs,from,keta);
        vec.pop_back();
        if(from+1<=9){
            vec.push_back(from+1);
            dfs(dfs,from+1,keta);
            vec.pop_back();
        }
    };
    
    for(Int keta=1;;keta++){
        for(Int i=1;i<=9;i++){
            vec.push_back(i);
            dfs(dfs,i,keta);
            vec.pop_back();
        }
        if(ansSet.size()>=k){
            rep(j,k-1){
                Int mi=*begin(ansSet);
                // cout<<mi<<endl;
                ansSet.erase(mi);
            }
            cout<<*begin(ansSet)<<endl;
            return 0;
        }
    }
    return 0;
}