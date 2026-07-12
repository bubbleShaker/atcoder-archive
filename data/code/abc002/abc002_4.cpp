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
    vector<set<Int>> v(n+1);
    rep(i,m) {
        Int x, y;
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }
    for(Int i = n; i >= 1; i--) {
        vector<Int> p(n);
        rep(j,i) p[j] = 1;
        sort(all(p));
        do {
            vector<Int> giin;
            rep(i,n) {
                if(p[i]) {
                    giin.push_back(i+1);
                }
            }
            bool fl = false;
            rep(i,giin.size()) {
                Int from = giin[i];
                for(Int j = i+1; j < giin.size(); j++) {
                    Int to = giin[j];
                    if(!v[from].count(to)) {
                        fl = true;
                    }
                    if(fl) break;
                }
                if(fl) break;
            }
            if(!fl) {
                cout << i << endl;
                return 0;
            }
        }while(next_permutation(all(p)));
    }
    return 0;
}