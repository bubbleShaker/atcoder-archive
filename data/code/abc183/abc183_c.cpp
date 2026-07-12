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
    
    Int n, k;
    cin >> n >> k;
    vector t(n,vl(n));
    rep(i,n)rep(j,n) cin >> t[i][j];
    vl p(n);
    rep(i,n) p[i] = i;
    sort(all(p));
    Int cnt = 0;
    do {
        if(p[0] == 0) {
            vl c = p;
            c.push_back(0);
            Int s = 0;
            rep(i,c.size()-1) {
                s += t[c[i]][c[i+1]];
            }
            if(s == k) cnt++;
        }
    }while(next_permutation(all(p)));
    cout << cnt << endl;
    return 0;
}