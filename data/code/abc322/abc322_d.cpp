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
//const vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
const vi dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;
vector<vs> p(3,vs(4));

vs rotVec(vs mino) {
    vs ret={"....","....","....","...."};
    for(Int i=0;i<4;i++){
        for(Int j=0;j<4;j++){
            ret[i][j]=mino[3-j][i];
        }
    }
    return ret;
}

int main(){
    fio()
    rep(i,3){
        rep(j,4)cin>>p[i][j];
    }
    vector<vs> newRotedP(3);
    rep(i,3)newRotedP[i]=p[i];
    rep(i,4){
        newRotedP[0]=rotVec(newRotedP[0]);
        rep(j,4){
            newRotedP[1]=rotVec(newRotedP[1]);
            rep(k,4){
                newRotedP[2]=rotVec(newRotedP[2]);
                vector<vs> ver2NewRotedP(3);
                vl pMaX(3),pMiX(3),pMaY(3),pMiY(3);
                rep(i,3){pMaX[i]=0;pMaY[i]=0;}
                rep(i,3){pMiX[i]=INFL;pMiY[i]=INFL;}
                rep(hi,3){
                    rep(hj,4){
                        rep(hk,4){
                            if(newRotedP[hi][hj][hk]=='#'){
                                chmax(pMaX[hi],hj);
                                chmax(pMaY[hi],hk);
                                chmin(pMiX[hi],hj);
                                chmin(pMiY[hi],hk);
                            }
                        }
                    }
                }
                rep(i,3){
                    for(Int j=pMiX[i];j<=pMaX[i];j++){
                        string tmpStr;
                        for(Int k=pMiY[i];k<=pMaY[i];k++){
                            tmpStr+=newRotedP[i][j][k];
                        }
                        ver2NewRotedP[i].push_back(tmpStr);
                    }
                }
                rep(p1i,4){
                    rep(p1j,4){
                        Int yokoP1=ver2NewRotedP[0][0].size(),tateP1=ver2NewRotedP[0].size();
                        rep(p2i,4){
                            rep(p2j,4){
                                Int yokoP2=ver2NewRotedP[1][0].size(),tateP2=ver2NewRotedP[1].size();
                                rep(p3i,4){
                                    rep(p3j,4){
                                        Int yokoP3=ver2NewRotedP[2][0].size(),tateP3=ver2NewRotedP[2].size();
                                        vvl checkVec(4,vl(4));
                                        if(p1i+tateP1-1>=4||p1j+yokoP1-1>=4)continue;
                                        for(Int ci=p1i;ci<p1i+tateP1;ci++){
                                            for(Int cj=p1j;cj<p1j+yokoP1;cj++){
                                                if(ver2NewRotedP[0][ci-p1i][cj-p1j]=='#')checkVec[ci][cj]++;
                                            }
                                        }
                                        if(p2i+tateP2-1>=4||p2j+yokoP2-1>=4)continue;
                                        for(Int ci=p2i;ci<p2i+tateP2;ci++){
                                            for(Int cj=p2j;cj<p2j+yokoP2;cj++){
                                                if(ver2NewRotedP[1][ci-p2i][cj-p2j]=='#')checkVec[ci][cj]++;
                                            }
                                        }
                                        if(p3i+tateP3-1>=4||p3j+yokoP3-1>=4)continue;
                                        for(Int ci=p3i;ci<p3i+tateP3;ci++){
                                            for(Int cj=p3j;cj<p3j+yokoP3;cj++){
                                                if(ver2NewRotedP[2][ci-p3i][cj-p3j]=='#')checkVec[ci][cj]++;
                                            }
                                        }
                                        bool isOk=true;
                                        rep(ci,4){
                                            rep(cj,4){
                                                if(checkVec[ci][cj]!=1)isOk=false;
                                            }
                                        }
                                        if(isOk){
                                            cout<<"Yes"<<endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}