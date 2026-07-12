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
// const vl dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
// const vl dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};
//const ll MOD = 1000000007;
const ll MOD = 998244353;

Int n;
vs h,v;
vs res(9),mi_res(9);
vvl d;
vector<vvl> rswD(9);
vd s_(9),mi_s(9);
vvl dxBase={
    {-1,0,1,0},
    {-1,0,1,0},
    {0,-1,0,1},
    {0,1,0,-1},
    {1,0,-1,0},
    {1,0,-1,0},
    {0,1,0,-1},
    {0,-1,0,1}
};
vvl dyBase={
    {0,1,0,-1},
    {0,-1,0,1},
    {1,0,-1,0},
    {1,0,-1,0},
    {0,1,0,-1},
    {0,-1,0,1},
    {-1,0,1,0},
    {-1,0,1,0}
};
vs strBase={
    "URDL",
    "ULDR",
    "RULD",
    "RDLU",
    "DRUL",
    "DLUR",
    "LDRU",
    "LURD"
};
set<lP> tileSet;
vector<lP> resPs;
vs resVec;
Int visitedCnt=0;

string solve(Int r,Int p,Int t){
    const vl dx=dxBase[r-1], dy=dyBase[r-1];
    vector<vector<bool>> visited(n,vector<bool>(n));
    string str=strBase[r-1];
    string goRt;
    Int isBack=-1;
    set<lP> st;
    Int turn=0;
    double stSum=0;

    auto incD = [&]() {
        rep(i,n)rep(j,n)rswD[r][i][j]+=d[i][j];
    };

    auto stPl = [&]() {
        rep(i,n)rep(j,n)stSum+=rswD[r][i][j];
    };

    auto bfsToZero = [&](Int x,Int y,string &tmpAns) -> void {
        queue<lP> q;
        q.push(lP(x,y));
        vvl checked(n,vl(n,-1));
        checked[x][y]=0;

        while(!q.empty()){
            auto [nowX,nowY]=q.front();
            q.pop();
            rep(i,4){
                Int nx=nowX+dx[i],ny=nowY+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                switch(str[i]){
                    case 'U':
                        if(h[nx][ny]=='1')continue;
                        break;
                    case 'R':
                        if(v[nowX][nowY]=='1')continue;
                        break;
                    case 'D':
                        if(h[nowX][nowY]=='1')continue;
                        break;
                    case 'L':
                        if(v[nx][ny]=='1')continue;
                        break;
                }
                if(checked[nx][ny]!=-1)continue;
                checked[nx][ny]=checked[nowX][nowY]+1;
                q.emplace(nx,ny);
            }
        }
        Int tmpX=0,tmpY=0;
        while(!(tmpX==x&&tmpY==y)){
            rep(i,4){
                Int nx=tmpX+dx[i],ny=tmpY+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                switch(str[i]){
                    case 'U':
                        if(h[nx][ny]=='1')continue;
                        break;
                    case 'R':
                        if(v[tmpX][tmpY]=='1')continue;
                        break;
                    case 'D':
                        if(h[tmpX][tmpY]=='1')continue;
                        break;
                    case 'L':
                        if(v[nx][ny]=='1')continue;
                        break;
                }

                auto rswRoutine = [&](Int nx,Int ny) -> void {
                    incD();
                    rswD[r][nx][ny]=0;
                    stPl();
                };

                if(checked[nx][ny]==checked[tmpX][tmpY]-1){
                    switch(str[i]){
                        case 'U':
                            tmpAns+='D';
                            rswRoutine(nx,ny);
                            break;
                        case 'R':
                            tmpAns+='L';
                            rswRoutine(nx,ny);
                            break;
                        case 'D':
                            tmpAns+='U';
                            rswRoutine(nx,ny);
                            break;
                        case 'L':
                            tmpAns+='R';
                            rswRoutine(nx,ny);
                            break;
                    }
                    tmpX=nx;
                    tmpY=ny;
                    break;
                }
            }
        }
        reverse(all(tmpAns));
    };

    auto bfs = [&](Int x,Int y,string &tmpAns,set<lP> &st) -> lP {
        queue<lP> q;
        q.push(lP(x,y));
        vvl checked(n,vl(n,-1));
        checked[x][y]=0;
        Int lx,ly;

        while(!q.empty()){
            auto [nowX,nowY]=q.front();
            q.pop();
            if(!st.count(lP(nowX,nowY))){
                lx=nowX;
                ly=nowY;
                break;
            }
            rep(i,4){
                Int nx=nowX+dx[i],ny=nowY+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                switch(str[i]){
                    case 'U':
                        if(h[nx][ny]=='1')continue;
                        break;
                    case 'R':
                        if(v[nowX][nowY]=='1')continue;
                        break;
                    case 'D':
                        if(h[nowX][nowY]=='1')continue;
                        break;
                    case 'L':
                        if(v[nx][ny]=='1')continue;
                        break;
                }
                if(checked[nx][ny]!=-1)continue;
                checked[nx][ny]=checked[nowX][nowY]+1;
                q.emplace(nx,ny);
            }
        }
        Int tmpX=lx,tmpY=ly;
        st.insert(lP(lx,ly));
        while(!(tmpX==x&&tmpY==y)){
            rep(i,4){
                Int nx=tmpX+dx[i],ny=tmpY+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                switch(str[i]){
                    case 'U':
                        if(h[nx][ny]=='1')continue;
                        break;
                    case 'R':
                        if(v[tmpX][tmpY]=='1')continue;
                        break;
                    case 'D':
                        if(h[tmpX][tmpY]=='1')continue;
                        break;
                    case 'L':
                        if(v[nx][ny]=='1')continue;
                        break;
                }

                auto rswRoutine = [&](Int nx,Int ny) -> void {
                    incD();
                    rswD[r][nx][ny]=0;
                    stPl();
                };

                if(checked[nx][ny]==checked[tmpX][tmpY]-1){
                    switch(str[i]){
                        case 'U':
                            tmpAns+='D';
                            rswRoutine(nx,ny);
                            break;
                        case 'R':
                            tmpAns+='L';
                            rswRoutine(nx,ny);
                            break;
                        case 'D':
                            tmpAns+='U';
                            rswRoutine(nx,ny);
                            break;
                        case 'L':
                            tmpAns+='R';
                            rswRoutine(nx,ny);
                            break;
                    }
                    tmpX=nx;
                    tmpY=ny;
                    break;
                }
            }
        }
        reverse(all(tmpAns));
        return lP(lx,ly);
    };
    
    auto bfs2 = [&](Int x,Int y,string &tmpAns,set<lP> &st) -> lP {
        queue<lP> q;
        q.push(lP(x,y));
        vvl checked(n,vl(n,-1));
        checked[x][y]=0;
        Int lx,ly;

        while(!q.empty()){
            auto [nowX,nowY]=q.front();
            q.pop();
            if(tileSet.count(lP(nowX,nowY))){
                lx=nowX;
                ly=nowY;
                break;
            }
            rep(i,4){
                Int nx=nowX+dx[i],ny=nowY+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                switch(str[i]){
                    case 'U':
                        if(h[nx][ny]=='1')continue;
                        break;
                    case 'R':
                        if(v[nowX][nowY]=='1')continue;
                        break;
                    case 'D':
                        if(h[nowX][nowY]=='1')continue;
                        break;
                    case 'L':
                        if(v[nx][ny]=='1')continue;
                        break;
                }
                if(checked[nx][ny]!=-1)continue;
                checked[nx][ny]=checked[nowX][nowY]+1;
                q.emplace(nx,ny);
            }
        }
        Int tmpX=lx,tmpY=ly;
        st.insert(lP(lx,ly));
        while(!(tmpX==x&&tmpY==y)){
            rep(i,4){
                Int nx=tmpX+dx[i],ny=tmpY+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                switch(str[i]){
                    case 'U':
                        if(h[nx][ny]=='1')continue;
                        break;
                    case 'R':
                        if(v[tmpX][tmpY]=='1')continue;
                        break;
                    case 'D':
                        if(h[tmpX][tmpY]=='1')continue;
                        break;
                    case 'L':
                        if(v[nx][ny]=='1')continue;
                        break;
                }

                auto rswRoutine = [&](Int nx,Int ny) -> void {
                    incD();
                    rswD[r][nx][ny]=0;
                    stPl();
                };

                if(checked[nx][ny]==checked[tmpX][tmpY]-1){
                    switch(str[i]){
                        case 'U':
                            tmpAns+='D';
                            rswRoutine(nx,ny);
                            break;
                        case 'R':
                            tmpAns+='L';
                            rswRoutine(nx,ny);
                            break;
                        case 'D':
                            tmpAns+='U';
                            rswRoutine(nx,ny);
                            break;
                        case 'L':
                            tmpAns+='R';
                            rswRoutine(nx,ny);
                            break;
                    }
                    tmpX=nx;
                    tmpY=ny;
                    break;
                }
            }
        }
        reverse(all(tmpAns));
        return lP(lx,ly);
    };

    auto dfs = [&](auto dfs,Int x,Int y) -> void {
        st.insert(lP(x,y));
        turn++;
        if((turn%((n*n)/p)==0||(turn==1&&t==1))&&visitedCnt<=(n*n*80)/100){
            Int nx=x,ny=y;
            set<lP> cpSet=tileSet;
            while(tileSet.size()!=0){
                string tmpAns;
                auto [lx,ly]=bfs2(nx,ny,tmpAns,st);
                goRt+=tmpAns;
                tileSet.erase(lP(lx,ly));
                nx=lx;
                ny=ly;
            }
            tileSet=cpSet;
            dfs(dfs,nx,ny);
            return;
        }
        if(st.size()==n*n){
            string tmpAns;
            bfsToZero(x,y,tmpAns);
            goRt+=tmpAns;
            s_[r]=stSum/(double)goRt.size();
            return;
        }
        incD();
        visited[x][y]=true;
        visitedCnt++;
        rswD[r][x][y]=0;
        stPl();
        rep(i,4){
            Int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=n)continue;
            switch(str[i]){
                case 'U':
                    if(h[nx][ny]=='1')continue;
                    break;
                case 'R':
                    if(v[x][y]=='1')continue;
                    break;
                case 'D':
                    if(h[x][y]=='1')continue;
                    break;
                case 'L':
                    if(v[nx][ny]=='1')continue;
                    break;
            }
            if(!visited[nx][ny]){
                isBack=-1;
                goRt+=str[i];
                dfs(dfs,nx,ny);
                return;
            }
        }
        string tmpAns;
        auto [lx,ly]=bfs(x,y,tmpAns,st);
        goRt+=tmpAns;
        dfs(dfs,lx,ly);
    };

    dfs(dfs,0,0);
    return goRt;
}

void solve2(Int r,string rt){
    const vl dx={-1,0,1,0},dy={0,1,0,-1};
    Int x=0,y=0;
    Int sz=rt.size();
    double stSum=0;

    auto incD = [&]() {
        rep(i,n)rep(j,n)rswD[r][i][j]+=d[i][j];
    };

    auto stPl = [&]() {
        rep(i,n)rep(j,n)stSum+=rswD[r][i][j];
    };

    auto rswRoutine = [&](Int nx,Int ny) -> void {
        incD();
        rswD[r][nx][ny]=0;
        stPl();
    };

    rswRoutine(x,y);

    rep(i,sz){
        Int ind;
        if(rt[i]=='U')ind=0;
        else if(rt[i]=='R')ind=1;
        else if(rt[i]=='D')ind=2;
        else if(rt[i]=='L')ind=3;
        Int nx=x+dx[ind],ny=y+dy[ind];
        rswRoutine(nx,ny);
        x=nx;
        y=ny;
    }
    s_[r]=stSum/(double)rt.size();
}

void input(){
    fio()
    srand((unsigned)time(NULL));
    cin>>n;
    h.resize(n-1);
    v.resize(n);
    d.resize(n,vl(n));
    for(Int i=1;i<=8;i++){
        rswD[i].resize(n,vl(n));
    }
    rep(i,n-1)cin>>h[i];
    rep(i,n)cin>>v[i];
    rep(i,n)rep(j,n)cin>>d[i][j];
}

void makeSearchTileSet(Int p){
    Int collectNum=(n*n)/p;
    vector<pair<Int,lP>> dVec;
    rep(i,n)rep(j,n){
        dVec.emplace_back(d[i][j],lP(i,j));
    }
    sort(rall(dVec));
    rep(i,collectNum){
        tileSet.insert(dVec[i].second);
    }
}

void makeData(){
    Int cnt=0;
    Int miTurn=1,maTurn;
    Int miTile=3,maTile;
    Int rMi=1,rMa=2;
    if(n>=39){
        maTurn=4;
        maTile=5;
    }else if(n>=35){
        maTurn=4;
        maTile=6;
    }else if(n>=30){
        maTurn=4;
        maTile=8;
    }else if(n>=25){
        maTurn=6;
        maTile=8;
    }else if(n>=24){
        maTurn=7;
        maTile=8;
    }else{
        maTurn=9;
        maTile=10;
    }
    for(Int r=rMi;r<=rMa;r++){
        for(Int p=miTile;p<=maTile;p++){
            makeSearchTileSet(p);
            for(Int i=miTurn;i<=maTurn;i++){
                for(Int j=1;j<=2;j++){
                    res[r]=solve(r,i,j);
                    solve2(r,res[r]);
                    resPs.emplace_back(s_[r],cnt);
                    resVec.push_back(res[r]);
                    cnt++;
                    visitedCnt=0;
                }
            }
            tileSet.erase(all(tileSet));
        }
    }
    sort(all(resPs));
}

void out(){
    cout<<resVec[resPs[0].second];
}

int main(){
    input();
    makeData();
    out();
    return 0;
}