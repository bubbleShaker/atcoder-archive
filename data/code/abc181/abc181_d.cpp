#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
//using mint = modint1000000007;
using mint = modint998244353;
#define pb(a) push_back(a)
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define rep2(i,x,y) for(Int i = x; i < (Int)y; ++i)
#define rrep(i,n) for (Int i=n;i>=0;i--)
#define rrep2(i,a,b) for (Int i=a;i>=b;i--)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
// const vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
const ll MOD = 1000000007;
// const ll MOD = 998244353;

string s;

void input(){
    fio()
    cin>>s;
}

string solve(string s){
    vl cnt(10);
    rep(i,s.size()){
        cnt[s[i]-'0']++;
    }
    if(s.size()==1){
        if(s[0]!='8'){
            return "No";
        }
        cnt[0]+=2;
    }else if(s.size()==2){
        string tmp=s;
        reverse(all(tmp));
        if(stoll(s)%8!=0&&stoll(tmp)%8!=0){
            return "No";
        }
        cnt[0]++;
    }

    auto f = [&](Int i,Int j,Int k){
        return 100*i+10*j+k;
    };
    
    for(Int i=0;i<=9;i++){
        for(Int j=0;j<=9;j++){
            for(Int k=0;k<=9;k++){
                Int num=f(i,j,k);
                // cout<<num<<endl;
                if(num%8==0){
                    vl nowCnt(10);
                    nowCnt[i]++;nowCnt[j]++;nowCnt[k]++;
                    if(nowCnt[i]>cnt[i]||nowCnt[j]>cnt[j]||nowCnt[k]>cnt[k])continue;
                    return "Yes";
                }
            }
        }
    }
    return "No";
}

int main(){
    input();
    string ns="No";
    auto f = [&](Int i,Int j,Int k){
        return 100*i+10*j+k;
    };
    cout<<solve(s)<<endl;
    // for(Int i=0;i<=9;i++){
    //     for(Int j=0;j<=9;j++){
    //         for(Int k=0;k<=9;k++){
    //             Int num=f(i,j,k);
    //             ns="No";
    //             if(num%8==0){
    //                 ns="Yes";
    //             }
    //             s=to_string(num);
    //             if(solve(s)!=ns){
    //                 cout<<"Here,"<<num<<endl;
    //                 cout<<"solve(s) is "<<solve(s)<<endl;
    //                 cout<<"s is "<<s<<endl;
    //                 cout<<"ns is "<<ns<<endl;
    //                 cout<<"--"<<endl;
    //             }
    //         }
    //     }
    // }
    return 0;
}