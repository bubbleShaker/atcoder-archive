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

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    Int n;
    cin >> n;
    vector<Int> a(n);
    rep(i,n) cin >> a[i];
    auto gcd_vec = [&](vector<ll>& a) {
        Int size = a.size();
        ll ret = a[0];
        for(Int i = 1; i < size; i++) {
            ret = gcd(ret,a[i]);
        }
        return ret;
    };
    if(gcd_vec(a) > 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    vector<bool> checked(1000005);
    vector<vector<Int>> pfv(1000005);
    checked[1] = true;
    for(int i = 2; i < 1000005; i++) {
        if(checked[i]) continue;
        for(int j = i; j <= 1000005; j+=i) {
            pfv[j].push_back(i);
            checked[j] = true;
        }
    }
    vector<int> cnt(1000005);
    rep(i,n) {
        for(auto prime : pfv[a[i]]) {
            cnt[prime]++;
            if(cnt[prime] > 1) {
                cout << "setwise coprime" << endl;
                return 0;
            }
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}