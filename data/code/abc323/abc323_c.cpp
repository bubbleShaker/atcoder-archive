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
//using mint = modint1000000007;
using mint = modint998244353;
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
    
    Int n, m; cin >> n >> m;
    vl a(m);
    rep(i,m) cin >> a[i];
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vl sum(n);
    multiset<Int> st;
    vector<vector<Int>> prob(n); //i番目の人がまだ解いていない問題
    rep(i,n) {
        rep(j,m) {
            if(s[i][j] == 'o') sum[i]+=a[j];
            else prob[i].push_back(a[j]);
        }
        sum[i]+=i+1;
    }
    rep(i,n) sort(rall(prob[i]));
    rep(i,n) st.insert(sum[i]);
    rep(i,n) {
        st.erase(sum[i]);
        Int nsum = sum[i];
        Int ma = *rbegin(st);
        Int cnt = 0;
        rep(j,prob[i].size()) {
            if(nsum > ma) break;
            nsum += prob[i][j];
            cnt++;
        }
        cout << cnt << endl;
        st.insert(sum[i]);
    }
    return 0 ;
}