#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
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
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

int main(){
    fio();
    
    Int n; cin >> n;
    string s; cin >> s;
    vl v(n);
    rep(i,n) {
        if(s[i] == '(') {
            v[i] = 1;
        }else v[i] = -1;
    }
    deque<lP> q;
    q.emplace_back(v[0],1);
    for(Int i = 1; i < n; i++) {
        bool fl = false;
        if(q.size() == 0) {
            q.emplace_back(v[i],1);
            fl = true;
        }
        if(fl) continue;
        auto &[val,cnt] = q.back();
        Int nval = v[i];
        if(nval == -1) { //右括弧だったら
            if(val == -1) {
                cnt++;
            }else {
                cnt--;
                if(cnt == 0) { //もし対応する左括弧が無くなったら消す
                    q.pop_back();
                }
            }
        }else { //左括弧だったら
            if(val == 1) {
                cnt++;
            }else {
                q.emplace_back(nval,1);
            }
        }
    }
    Int l = 0, r = 0;
    for(auto [val,cnt] : q) {
        if(val == -1) {
            l += cnt;
        }
        if(val == 1) {
            r += cnt;
        }
    }
    string ans = s;
    rep(i,r) {
        ans += ')';
    }
    reverse(all(ans));
    rep(i,l) {
        ans += '(';
    }
    reverse(all(ans));
    cout << ans << endl;
    return 0;
}