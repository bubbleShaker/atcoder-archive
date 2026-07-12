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
using mint = modint1000000007;
//using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    
    Int k; cin >> k;
    string s,t; cin >> s >> t;
    Int bunbo = (double)(9*k-8)*(9*k-9);
    Int bunshi = 0;
    vl c(10,k);
    rep(i,4) {
        c[s[i]-'0']--;
        c[t[i]-'0']--;
    }
    
    auto eval = [&](string s) {
        Int ret = 0;
        vl cnt(10);
        rep(i,s.size()) {
            cnt[s[i]-'0']++;
        }
        for(Int i = 1; i <= 9; i++) {
            ret += i*(Int)pow(10,(double)cnt[i]);
        }
        return ret;
    };
    
    for(Int i = 1; i <= 9; i++) {
        for(Int j = 1; j <= 9; j++) {
            s.back() = '0'+i;
            t.back() = '0'+j;
            if(eval(s) > eval(t)) {
                bunshi += c[i]*(c[j]-(i==j));
            }
        }
    }
    sp(10)
    cout << (double)bunshi/bunbo << endl;
    return 0 ;
}