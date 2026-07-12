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
using fT = tuple<ll,ll,ll,ll>;
using dT = tuple<double,double,double>;
//using mint = modint1000000007;
using mint = modint998244353;
#define pb(a) push_back(a)
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
//#define rep(i,x,y) for(Int i = x; i < (Int)y; ++i)
//#define rep(i,x,y) for(Int i = x; i <= (Int)y; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;

int main(){
    fio()
    Int n; cin >> n;
    map<string,Int> mp;
    rep(i,n) {
        string s; cin >> s;
        mp[s]++;
    }
    Int num = 0;
    using Istr = pair<Int,string>;
    vector<pair<Int,string>> ps;
    for(auto [str,cnt] : mp) {
        ps.emplace_back(cnt,str);
    }
    sort(all(ps),[&](Istr a,  Istr b) {
        if(a.first == b.first) return a.second <= b.second;
        return a.first >= b.first;
    });
    Int firstCnt = ps[0].first;
    rep(i,ps.size()) {
        if(ps[i].first != firstCnt) break;
        cout << ps[i].second << endl;
    }
    // for(auto [str,cnt] : mp) {
    //     if(num == 0) {
    //         num = cnt;
    //         cout << str << endl;
    //     }else {
    //         if(num == cnt) {
    //             cout << str << endl;
    //         }else break;
    //     }
    // }
    return 0 ;
}