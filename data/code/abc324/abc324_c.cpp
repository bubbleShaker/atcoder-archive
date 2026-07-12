#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vd = vector<double>;
using vl = vector<ll>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
//using mint = modint998244353;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio()
    
    Int n; cin >> n;
    string t; cin >> t;
    vl ans;
    rep(i,n) {
        string s; cin >> s;
        if(t.size() == s.size()) {
            if(t == s) {
                ans.push_back(i+1);
            }else {
                Int cnt = 0;
                rep(j,t.size()) {
                    if(s[j] != t[j]) cnt++;
                }
                if(cnt == 1) {
                    ans.push_back(i+1);
                }
            }
        }else if(t.size() == s.size()-1) {
            string ns;
            rep(j,s.size()) {
                if(j == s.size()-1) {
                    ans.push_back(i+1);
                    continue;
                }
                bool fl = false;
                if(s[j] != t[j]) {
                    ns+=s.substr(0,j);
                    ns+=s.substr(j+1);
                    fl = true;
                }
                if(fl) break;
            }
            if(ns == t) {
                ans.push_back(i+1);
            }
        }else if(t.size() == s.size()+1) {
            string ns;
            rep(j,t.size()) {
                if(j == t.size()-1) {
                    ans.push_back(i+1);
                    continue;
                }
                bool fl = false;
                if(s[j] != t[j]) {
                    ns+=s.substr(0,j);
                    ns+=t[j];
                    ns+=s.substr(j);
                    fl = true;
                }
                if(fl) break;
            }
            if(ns == t) {
                ans.push_back(i+1);
            }
        }
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) {
        cout << ans[i] << " ";
    }
    return 0 ;
}