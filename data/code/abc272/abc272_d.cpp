#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, -1, 1};

int main(void){
    int n, m;
    cin >> n >> m;
    vector<P> ps;
    for(int i = 0; i <= m; i++) {
        int j = m-i;
        if(i == 0) {
            int srj = (int)sqrt(j);
            if(j == srj*srj) ps.emplace_back(i,srj);
            continue;
        }else if(j == 0) {
            int sri = (int)sqrt(i);
            if(i == sri*sri) ps.emplace_back(sri,j);
            continue;
        }
        int sri = (int)sqrt(i);
        int srj = (int)sqrt(j);
        if(i == sri*sri && j == srj*srj) ps.emplace_back(sri,srj);
    }
    vector ans(n+1, vector<int>(n+1,-1));
    queue<P> que;
    que.emplace(1,1);
    ans[1][1] = 0;
    
    while(!que.empty()) {
        auto [x,y] = que.front();
        que.pop();
        
        for(auto [xx,yy] : ps){
            rep(i,4) {
                int nx = x+xx*dx[i];
                int ny = y+yy*dy[i];
                if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
                if(ans[nx][ny] != -1) continue;
                que.emplace(nx,ny);
                ans[nx][ny] = ans[x][y]+1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n ; j++) {
            cout << ans[i][j] << " \n"[j+1 == n+1];
        }
    }
    return 0;
}
