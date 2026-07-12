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
    
    string s;
    cin >> s;
    char f = s[0];
    Int n = s.size();
    char l = s[n-1];
    if(n != 8) {
        cout << "No" << endl;
        return 0;
    }
    string m = s.substr(1,n-2);
    if(f >= 'A' && f <= 'Z') {
        if(l >= 'A' && f <= 'Z') {
            Int cnt = 0;
            rep(i,6) {
                if(i == 0) {
                    if(m[i]-'0' >= 1) cnt++;
                    continue;
                }
                if(m[i]-'0' >= 0 && m[i]-'0' <= 9) cnt++;
            }
            if(cnt == 6) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}