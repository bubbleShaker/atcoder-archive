#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector base(101, vector<int>(101));
    rep(i,n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j = a; j < b; j++) {
            for(int k = c; k < d; k++) {
                base[j][k] = 1;
            }
        }
    }
    int ans = 0;
    rep(i,101){
        rep(j,101) {
            if(base[i][j] == 1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
