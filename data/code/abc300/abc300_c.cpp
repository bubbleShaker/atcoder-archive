#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<bool>> seen(101, vector<bool>(101, false));
const int dx[4] = {1, 1, -1, -1};
const int dy[4] = {1, -1, 1, -1};
int co = 0;
int H, W;

void dfs(vector<string> &c, int x, int y){
    seen[x][y] = true;
    
    if(c[x][y] == '#'){
        co++;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            else if(!seen[nx][ny]) dfs(c, nx, ny);
            else continue;
        }
    }
    
    return;
}

int main(void){
    cin >> H >> W;
    
    vector<string> C(H);
    
    for(int i = 0; i < H; i++){
        cin >> C[i];
    }
    
    int N = min(H, W);
    
    vector<int> S(N+1);
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(!seen[i][j]) dfs(C, i, j);
            else continue;
            if(co > 0){
                int n = (co - 1) / 4;
                S[n]++;
                co = 0;
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        cout << S[i];
        if(i != N) cout << " ";
        else cout << endl;
    }
    
    return 0;
}
