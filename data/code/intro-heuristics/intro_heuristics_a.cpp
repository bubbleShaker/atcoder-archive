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
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using dII = tuple<double,Int,Int>;
using mint = modint1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    srand((unsigned)time(NULL));
    
    int D;
    const int INF = 1e9;
    cin >> D;
    vector<int> c(27);
    for(int i = 1; i <= 26; i++) cin >> c[i];
    vector s(D+1, vector<int>(27));
    for(int i = 1; i <= D; i++)for(int j = 1; j <= 26; j++) cin >> s[i][j];
    vector<int> last(27);
    vector<int> ans(D+1);
    int sum = 0;
    for(int d = 1; d <= D; d++) {
        int ma = -INF;
        int con = 0;
        for(int i = 1; i <= 26; i++) {
            int dsat = 0;
            dsat += s[d][i];
            int prelast = last[i];
            last[i] = d;
            int unsat = 0;
            for(int j = 1; j <= 26; j++) {
                unsat += c[j]*(d-last[j]);
            }
            dsat -= unsat;
            if(ma < dsat) {
                ma = dsat;
                con = i;
            }
            last[i] = prelast;
        }
        sum += ma;
        last[con] = d;
        ans[d] = con;
    }
    auto f = [&](vector<int> a) {
        int ret = 0;
        vector<int> nlast(27);
        for(int d = 1; d <= D; d++) {
            ret += s[d][a[d]];
            nlast[a[d]] = d;
            int sub = 0;
            for(int i = 1; i <= 26; i++) {
                sub += c[i]*(d-nlast[i]);
            }
            ret -= sub;
        }
        return ret;
    };
    
    int ti = clock();
    while(clock() - ti < 199*CLOCKS_PER_SEC/100) {
        int nd = (rand() % D)+1;
        int ni = (rand() % 26)+1;
        int pi = ans[nd];
        ans[nd] = ni;
        int nsum = f(ans);
        if(nsum < sum) {
            ans[nd] = pi;
        }else {
            sum = nsum;
        }
    }
    for(int d = 1; d <= D; d++) {
        cout << ans[d] << endl;
    }
    return 0;
}