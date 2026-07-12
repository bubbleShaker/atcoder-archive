#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void){
    int h, w;
    cin >> h >> w;
    vector<string> ss(h);
    rep(i,h) cin >> ss[i];
    string b = "snuke";
    rep(i,h) {
        rep(j,w) {
            int x = i;
            int y = j;
            rep(k,8) {
                rep(l, 5) {
                    int nx = x+l*dx[k];
                    int ny = y+l*dy[k];
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) break;
                    if(ss[nx][ny] != b[l]) break;
                    if(l == 4) {
                        rep(m,5) {
                            cout << x+m*dx[k]+1 << " " << y+m*dy[k]+1 << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
