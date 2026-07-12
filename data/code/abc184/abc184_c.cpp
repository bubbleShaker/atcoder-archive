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
    
    Int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(r1 == r2 && c1 == c2) {
        cout << 0 << endl;
        return 0;
    }
    if((abs(r1-r2)+abs(c1-c2) <= 3) || ((r1+c1) == (r2+c2)) || ((r1-c1) == (r2-c2))) {
        cout << 1 << endl;
        return 0;
    }
    if(abs(r1-r2)+abs(c1-c2) <= 6) {
        cout << 2 << endl;
        return 0;
    }
    if((r1+c1+r2+c2)%2 == 0) {
        cout << 2 << endl;
        return 0;
    }
    Int n = 3;
    bool fl = false;
    while(n != -4) {
        Int nx = r1+n;
        Int ny = c1;
        if(((nx+ny) == (r2+c2)) || ((nx-ny) == (r2-c2))) {
            fl = true;
            break;
        }
        n--;
    }
    if(fl) {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;
}