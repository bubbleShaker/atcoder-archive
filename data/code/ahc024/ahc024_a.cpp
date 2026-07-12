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
    
    Int n, m; cin >> n >> m;
    vector c(n,vector<Int>(n));
    vector base(n+2,vector<Int>(n+2, -1));
    for(Int i = 1; i <= n; i++)for(Int j = 1; j <= n; j++) {
        Int color;
        cin >> color;
        base[i][j] = color;
        c[i-1][j-1] = color;
    }
    vector ers(n,vector<Int>(n));
    
    //横についてみる
    Int X = 1;
    for(Int j = 1; j <= n; j++) {
        if(base[X][j] == base[X][j-1] && base[X][j] == base[X][j+1]) {
            if(base[X+1][j] != base[X][j]) continue;
            ers[X-1][j-1]++;
            continue;
        }
        if(base[X][j-1] == -1 && base[X][j] == base[X][j+1]) {
            if(base[X+1][j] != base[X][j]) continue;
            ers[X-1][j-1]++;
            continue;
        }
        if(base[X][j+1] == -1 && base[X][j] == base[X][j-1]) {
            if(base[X-1][j] != base[X][j]) continue;
            ers[X+1][j-1]++;
            continue;
        }
    }
    X = n;
    for(Int j = 1; j <= n; j++) {
        if(base[X][j] == base[X][j-1] && base[X][j] == base[X][j+1]) {
            if(base[X-1][j] != base[X][j]) continue;
            ers[X-1][j-1]++;
            continue;
        }
        if(base[X][j-1] == -1 && base[X][j] == base[X][j+1]) {
            if(base[X-1][j] != base[X][j]) continue;
            ers[X-1][j-1]++;
            continue;
        }
        if(base[X][j+1] == -1 && base[X][j] == base[X][j-1]) {
            if(base[X-1][j] != base[X][j]) continue;
            ers[X-1][j-1]++;
            continue;
        }
    }
    
    //縦についても見る
    Int Y = 1;
    for(Int i = 1; i <= n; i++) {
        if(base[i][Y] == base[i-1][Y] && base[i][Y] == base[i+1][Y]) {
            if(base[i][Y+1] != base[i][Y]) continue;
            ers[i-1][Y-1]++;
            continue;
        }
        if(base[i-1][Y] == -1 && base[i][Y] == base[i+1][Y]) {
            if(base[i][Y+1] != base[i][Y]) continue;
            ers[i-1][Y-1]++;
            continue;
        }
        if(base[i+1][Y] == -1 && base[i][Y] == base[i-1][Y]) {
            if(base[i][Y+1] != base[i][Y]) continue;
            ers[i-1][Y-1]++;
            continue;
        }
    }
    Y = n;
    for(Int i = 1; i <= n; i++) {
        if(base[i][Y] == base[i-1][Y] && base[i][Y] == base[i+1][Y]) {
            if(base[i][Y-1] != base[i][Y]) continue;
            ers[i-1][Y-1]++;
            continue;
        }
        if(base[i-1][Y] == -1 && base[i][Y] == base[i+1][Y]) {
            if(base[i][Y-1] != base[i][Y]) continue;
            ers[i-1][Y-1]++;
            continue;
        }
        if(base[i+1][Y] == -1 && base[i][Y] == base[i-1][Y]) {
            if(base[i][Y-1] != base[i][Y]) continue;
            ers[i-1][Y-1]++;
            continue;
        }
    }
    
    rep(i,n)rep(j,n) {
        if(ers[i][j] != 0) c[i][j] = 0;
    }
    
    //角を繋げる
    //上、左の折れる部分を繋げる|-
    rep(i,n-1)rep(j,n-1) {
        if(c[i][j] == 0) {
            if(c[i][j+1] == c[i+1][j]) {
                if(c[i][j+1] != c[i+1][j+1]) {
                    c[i][j] = c[i][j+1];
                }
            }
        }
    }
    
    //右、上を繋げる
    rep(i,n-1)for(Int j = 1; j < n; j++) {
        if(c[i][j] == 0) {
            if(c[i][j-1] == c[i+1][j]) {
                if(c[i][j-1] != c[i+1][j-1]) {
                    c[i][j] = c[i][j-1];
                }
            }
        }
    }
    
    //右、下を繋げる
    for(Int i = 1; i < n; i++)for(Int j = 1; j < n; j++) {
        if(c[i][j] == 0) {
            if(c[i][j-1] == c[i-1][j]) {
                if(c[i][j-1] != c[i-1][j-1]) {
                    c[i][j] = c[i][j-1];
                }
            }
        }
    }
    
    //左、下を繋げる
    for(Int i = 1; i < n; i++)rep(j,n-1) {
        if(c[i][j] == 0) {
            if(c[i][j+1] == c[i-1][j]) {
                if(c[i][j+1] != c[i-1][j+1]) {
                    c[i][j] = c[i][j+1];
                }
            }
        }
    }
    
    //結果出力
    rep(i,n)rep(j,n) {
        cout << c[i][j] << " \n"[j+1 == n];
    }
}