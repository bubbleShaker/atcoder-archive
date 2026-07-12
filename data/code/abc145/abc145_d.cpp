#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double,double>;
using dII = tuple<double,Int,Int>;
using mint = modint1000000007;

const int MAX = 5100000;
mint fac[MAX], finv[MAX], inv[MAX];

void factable() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = i*fac[i-1];
        inv[i] = MOD - inv[MOD%i]*(MOD/i);
        finv[i] = inv[i]*finv[i-1];
    }
}

mint com(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n]*finv[k]*finv[n-k];
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int x, y;
    cin >> x >> y;
    if((2*y-x)%3 !=0 || (2*x-y)%3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int dy = (2*y-x)/3;
    int dx = (2*x-y)/3;
    const int N = dx+dy;
    const int K = dx;
    factable();
    cout << com(N,K).val() << endl;
    return 0;
}