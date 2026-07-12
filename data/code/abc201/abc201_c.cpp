#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    string s;
    cin >> s;
    int ans = 0;
    rep(num,10000) {
        vector<int> a(10);
        int x = num;
        rep(i,4) {
            int d = x%10;
            a[d] = 1;
            x /= 10;
        }
        bool ok = true;
        rep(i,10) {
            if(s[i] == 'o' && a[i] != 1) ok = false;
            if(s[i] == 'x' && a[i] != 0) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
