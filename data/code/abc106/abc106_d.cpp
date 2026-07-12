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
//using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
//using mint = modint1000000007;
using mint = modint998244353;
#define pb(a) push_back(a)
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
//#define rep(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define REP(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const ll MOD = 1000000007;
//const ll MOD = 998244353;
using fT = tuple<ll,ll,ll,ll>;

template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;                        // to be set
    
    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.sssign(n + 1, UNITY_SUM); }
    
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int N, M, Q;
typedef pair<int,int> pint;
typedef pair<pint,int> ipint;
vector<ipint> ins;
vector<int> alts;

bool cmp(ipint a, ipint b) {
    return make_pair(a.first.second, a.second) < make_pair(b.first.second, b.second);
}
 
int main(){
    fio()
    cin >> N >> M >> Q;
    ins.resize(M+Q);
    alts.clear();
    for(int i = 0; i < M + Q; i++) {
        cin >> ins[i].first.first >> ins[i].first.second;
        ins[i].first.second++;
        if(i<M) ins[i].second = -1; else ins[i].second = i-M;
        alts.push_back(ins[i].first.first), alts.push_back(ins[i].first.second);
    }
    sort(all(alts));
    alts.erase(unique(all(alts)),alts.end());
    sort(all(ins),cmp);
    for(int i = 0; i < M+Q; i++) {
        int left = lower_bound(all(alts),ins[i].first.first) - alts.begin();
        int right = lower_bound(all(alts), ins[i].first.second) - alts.begin();
        ins[i].first.first = left+1;
        ins[i].first.second = right+1;
    }
    BIT<int> bit((M+Q)*2+10);
    vector<int> res(Q);
    for(int i = 0; i < M+Q; i++) {
        if(ins[i].second == -1) bit.add(ins[i].first.first,1);
        else res[ins[i].second] = bit.sum(ins[i].first.first, ins[i].first.second);
    }
    for(int i = 0; i < Q; i++) cout << res[i] << endl;
    return 0 ;
}