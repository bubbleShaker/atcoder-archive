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
    
    // LCS dp[i][j]:sをi文字目、tをj文字目まで見た時の最長共通部分文字列の長さ
    string s, t; cin >> s >> t;
    Int n = s.size();
    Int m = t.size();
    vector dp(n+1, vl(m+1));
    for(Int i = 1; i <= n; i++) {
        for(Int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    Int len = dp[n][m];
    Int i = n;
    Int j = m;
    string ans;
    while(len > 0) {
        if(s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--;
            j--;
            len--;
        }else if(dp[i][j] == dp[i-1][j]) i--;
        else j--;
    }
    reverse(all(ans));
    cout << ans << endl;
    return 0;
}