#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    srand((unsigned)time(NULL));
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> per(n, vector<bool>(n));
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        per[a][b] = true;
        per[b][a] = true;
    }
    int ti = clock();
    
    Int sum = 0;
    Int ok = 0;
    while(clock() - ti < 499 * CLOCKS_PER_SEC / 100) {
        vector<int> v(n);
        rep(i,n) v[i] = i;
        rep(i,k) {
            int a = rand() % n;
            int b;
            do {
                b = rand() % n;
            }while(a == b);
            if(a != b) swap(v[a], v[b]);
        }
        bool fl = false;
        rep(i,n) {
            int p1 = v[i];
            int p2 = v[(i+1)%n];
            if(per[p1][p2]) {
                fl = true;
                break;
            }
        }
        if(!fl) ok++;
        sum++;
    }
    double ans = (double)ok / (double)sum;
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}