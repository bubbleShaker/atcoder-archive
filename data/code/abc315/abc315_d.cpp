#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector a(h, vector<int>(w));
    rep(i,h)rep(j,w) a[i][j] = c[i][j]-'a';
    
    const int m = 26;
    vector row(h, vector<int>(m));
    vector col(w, vector<int>(m));
    rep(i,h)rep(j,w) {
        row[i][a[i][j]]++;
        col[j][a[i][j]]++;
    }
    vector<bool> row_deleted(h);
    vector<bool> col_deleted(w);
    
    auto toDelete = [&](vector<int> x) {
        int total = 0, k = 0;
        rep(j,m) {
            total += x[j];
            if (x[j]) k++;
        }
        return total >= 2 && k == 1;
    };
    auto del = [&](int i, int j) {
        if(row_deleted[i] || col_deleted[j]) return;
        row[i][a[i][j]]--;
        col[j][a[i][j]]--;
    };
    
    bool upd = true;
    while(upd) {
        upd = false;
        vector<int> del_row, del_col;
        rep(i,h) {
            if(row_deleted[i]) continue;
            if(toDelete(row[i])) del_row.push_back(i);
        }
        rep(j,w) {
            if(col_deleted[j]) continue;
            if(toDelete(col[j])) del_col.push_back(j);
        }
        for(int i : del_row) {
            rep(j,w) del(i,j);
            row_deleted[i] = true;
            upd = true;
        }
        for(int j : del_col) {
            rep(i,h) del(i,j);
            col_deleted[j] = true;
            upd = true;
        }
    }
    
    int ans = 0;
    rep(i,h)rep(j,w) {
        if (row_deleted[i] || col_deleted[j]) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}