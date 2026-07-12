#include <bits/stdc++.h>
using namespace std;

int h, w, k;
int ans = 0;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

void dfs(vector<string>& s, int x, int y, int depth) {
    if (depth == k) {
        ans++;
        return;
    }
    
    // 現在の位置を一時的に訪問済みにする
    char original = s[x][y];
    s[x][y] = '#';
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == '.') {
            dfs(s, nx, ny, depth + 1);
        }
    }
    
    // 元の状態に戻す
    s[x][y] = original;
}

int main() {
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                dfs(s, i, j, 0);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
