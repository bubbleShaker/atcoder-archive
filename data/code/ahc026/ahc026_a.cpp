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
#define rrep(i,n) for (Int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (Int i = (a)-1;i>=b;i--)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
#define X first
#define Y second
#define sp(X) cout << fixed << setprecision(X);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define foa(e, v) for(auto& e : v)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;

Int n,m;
vvl b;

void input(){
    fio()
    cin>>n>>m;
    b.resize(m,vl(n/m));
    rep(i,m)rep(j,n/m){ cin>>b[i][j]; b[i][j]--; }
}



int main(){
    srand((unsigned)time(NULL));
    input();
    rep(i,n){
        bool isHere=false;
        // cout<<i<<" is i"<<endl;
        rep(j,m){
            if(isHere)break;
            Int nowSizeofB=b[j].size();
            rep(k,nowSizeofB){
                if(b[j][k]==i) { isHere=true; break; }
            }
            if(!isHere)continue;
            //取り出す値を見つけた後
            vector<Int> eraseVec;//iより上の箱
            vector<Int> beforeVec;//iより↓の箱
            bool isBefore=true;
            rep(k,nowSizeofB){
                if(isBefore==false){
                    eraseVec.push_back(b[j][k]);
                    continue;
                }
                if(b[j][k]==i){
                    isBefore=false;
                }else{
                    beforeVec.push_back(b[j][k]);
                }
            }
            Int nextMount=j;
            vector<lP> ps;
            bool foundNext=false;
            rep(k,m){
                ps.emplace_back(b[k].size(),k);
            }
            sort(rall(ps));
            for(auto [sz,mnt]:ps){
                if(j==mnt)continue;
                nextMount=mnt;
            }
            
            auto resizeVec = [&](vl a, vl b){
                vl ret;
                rep(i,a.size())ret.push_back(a[i]);
                rep(i,b.size())ret.push_back(b[i]);
                return ret;
            };
            
            b[j]=beforeVec;
            
            b[nextMount]=resizeVec(b[nextMount],eraseVec);
            
            if(eraseVec.size()==0){
                cout<<i+1<<" "<<nextMount+1<<endl;
            }else{
                cout<<eraseVec[0]+1<<" "<<nextMount+1<<endl;
            }
            cout<<i+1<<" "<<0<<endl;//i番目を出荷する
            // while(eraseVec.size()){//iより上の箱を全て移動させるまで
            //     set<Int> eleSet;
            //     rep(k,eraseVec.size()){
            //         eleSet.insert(eraseVec[k]);
            //     }
            //     vector<Int> remainVec;
            //     vector<Int> stuckVec;
            //     bool isFound=false;
            //     rep(k,eraseVec.size()){
            //         if(isFound)stuckVec.push_back(eraseVec[k]);
            //         else{
            //             if(*rbegin(eleSet)==eraseVec[k]){
            //                 isFound=true;
            //                 stuckVec.push_back(eraseVec[k]);
            //             }else{
            //                 remainVec.push_back(eraseVec[k]);
            //             }
            //         }
            //     }
            //     eraseVec=remainVec;
                
            //     auto resizeVec = [&](vl a, vl b){
            //         vl ret;
            //         rep(i,a.size())ret.push_back(a[i]);
            //         rep(i,b.size())ret.push_back(b[i]);
            //         return ret;
            //     };
                
            //     srand((unsigned)time(NULL));
            //     Int newMount=i;
            //     while(newMount==i){
            //         newMount=rand()%m;
            //     }
            //     b[newMount]=resizeVec(b[newMount],stuckVec);
            //     cout<<*rbegin(eleSet)<<" "<<newMount+1<<endl;
            // }
        }
    }
    return 0;
}