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
    
    string s, t;
    cin >> s >> t;
    if(s == t) {
        cout << "Yes" << endl;
        return 0;
    }
    int n = s.size();
    string cs = s;
    rep(i,n-1) {
        swap(s[i],s[i+1]);
        if(s == t) {
            cout << "Yes" << endl;
            return 0;
        }
        s = cs;
    }
    cout << "No" << endl;
    return 0;
}