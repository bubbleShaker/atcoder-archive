#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
//using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio();
    
    Int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string p1 = t.substr(0,n);
    reverse(all(t));
    string p2 = t.substr(0,n);
    reverse(all(t));
    reverse(all(s));
    string rs = s;
    reverse(all(s));
    rep(i,n) {
        if(s == p1 && rs == p2) {
            cout << 0 << endl;
            return 0;
        }else if(s == p1 && rs != p2) {
            cout << 1 << endl;
            return 0;
        }else if(s != p1 && rs == p2) {
            cout << 2 << endl;
            return 0;
        }else {
            cout << 3 << endl;
            return 0;
        }
    }
    return 0;
}