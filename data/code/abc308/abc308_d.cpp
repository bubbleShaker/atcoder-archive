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
vector<Int> dx = {-1,0,1,0};
vector<Int> dy = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    Int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    queue<lT> q;
    q.emplace(0,0,0);
    vector visited(h, vector<bool>(w));
    visited[0][0] = true;
    const string base = "snuke";
    
    while(!q.empty()) {
        auto [x,y,ind] = q.front();
        q.pop();
        
        rep(i,4) {
            Int nx = x+dx[i];
            Int ny = y+dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(visited[nx][ny]) continue;
            if(s[nx][ny] == base[(ind+1)%5]) {
                q.emplace(nx,ny,ind+1);
                visited[nx][ny] = true;
            }
        }
    }
    if(visited[h-1][w-1]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}