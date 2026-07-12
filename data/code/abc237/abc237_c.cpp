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
    Int cnt = 0;
    Int ind = 0;
    while(s[ind] == 'a') {
        cnt++;
        ind++;
    }
    reverse(all(s));
    ind = 0;
    Int cnt2 = 0;
    while(s[ind] == 'a') {
        ind++;
        cnt2++;
    }
    if(cnt2 < cnt) {
        cout << "No" << endl;
        return 0;
    }
    string cs = s.substr(cnt2);
    reverse(all(cs));
    rep(i,cnt) cs += 'a';
    string ccs = cs;
    reverse(all(ccs));
    if(ccs == cs) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}