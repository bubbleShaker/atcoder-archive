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
    
    Int n;
    cin >> n;
    vector<Int> v;
    Int k = 0;
    while(n > 0) {
        v.push_back(n%10);
        n /= 10;
        k++;
    }
    sort(v.begin(), v.end());
    Int ans = 0;
    do {
        rep(i,k-1) {
            Int a = 0;
            for(int j = 0; j <= i; j++) {
                a *= 10;
                a += v[j];
            }
            Int b = 0;
            for(int j = i+1; j < k; j++) {
                b *= 10;
                b += v[j];
            }
            ans = max(ans,a*b);
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}