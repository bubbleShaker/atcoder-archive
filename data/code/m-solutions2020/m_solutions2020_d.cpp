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
using bP = pair<ll,bool>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    Int n;
    cin >> n;
    vector<Int> a(n);
    rep(i,n) cin >> a[i];
    Int mo = 1000;
    Int kabu = 0;
    a.push_back(0);
    rep(i,n) {
        Int now = a[i];
        Int next = a[i+1];
        if(now < next) {
            kabu += mo/now;
            mo %= now;
        }else if(now > next) {
            mo += kabu*now;
            kabu = 0;
        }
    }
    cout << mo << endl;
    return 0;
}