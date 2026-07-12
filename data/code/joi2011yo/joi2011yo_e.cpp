#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<P> ps(n+1);
    rep(i,h)rep(j,w) {
        if(s[i][j] != '.' && s[i][j] != 'X' && s[i][j] != 'S') {
            int num = s[i][j] - '0';
            ps[num] = P(i,j);
        }else if(s[i][j] == 'S') {
            ps[0] = P(i,j);
        }
    }
    vector<int> ans(n);
    rep(i,n) {
        queue<T> q;
        auto [x,y] = ps[i];
        q.emplace(x,y,0);
        set<P> st;
        st.insert(P(x,y));
        bool fl = true;
        
        while(fl) {
            auto [x,y,d] = q.front();
            q.pop();
            
            rep(j,4) {
                int nx = x+dx[j];
                int ny = y+dy[j];
                if(nx >= h || ny >= w || nx < 0 || ny < 0) continue;
                if(s[nx][ny] == 'X') continue;
                if(st.count(P(nx,ny))) continue;
                if(s[nx][ny] == '.') {
                    q.emplace(nx,ny,d+1);
                    st.insert(P(nx,ny));
                }else {
                    int num = s[nx][ny]-'0';
                    if(num == i+1) {
                        ans[i] = d+1;
                        fl = false;
                    }else {
                        q.emplace(nx,ny,d+1);
                        st.insert(P(nx,ny));
                    }
                }
            }
        }
    }
    int sum = 0;
    rep(i,n) sum += ans[i];
    cout << sum << endl;
    return 0;
}