#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    Int n, m, k; cin >> n >> m >> k;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector m1(n,vector<Int>(m));
    vector m2(n,vector<Int>(m));
    vector m3(n,vector<Int>(m));
    vector s1(n+1, vector<Int>(m+1));
    vector s2(n+1, vector<Int>(m+1));
    vector s3(n+1, vector<Int>(m+1));
    rep(i,n)rep(j,m) {
        if(s[i][j] == 'J') {
            m1[i][j] = 1;
        }else if(s[i][j] == 'O') {
            m2[i][j] = 1;
        }else {
            m3[i][j] = 1;
        }
    }
    rep(i,n)rep(j,m) {
        s1[i+1][j+1] = s1[i][j+1]+s1[i+1][j]-s1[i][j]+m1[i][j];
    }
    rep(i,n)rep(j,m) {
        s2[i+1][j+1] = s2[i][j+1]+s2[i+1][j]-s2[i][j]+m2[i][j];
    }
    rep(i,n)rep(j,m) {
        s3[i+1][j+1] = s3[i][j+1]+s3[i+1][j]-s3[i][j]+m3[i][j];
    }
    rep(i,k) {
        Int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        Int ans1 = s1[c][d]-s1[a][d]-s1[c][b]+s1[a][b];
        Int ans2 = s2[c][d]-s2[a][d]-s2[c][b]+s2[a][b];
        Int ans3 = s3[c][d]-s3[a][d]-s3[c][b]+s3[a][b];
        cout << ans1 << " " << ans2 << " " << ans3 << endl;
    }
    return 0;
}