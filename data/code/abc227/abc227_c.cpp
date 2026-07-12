#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    ll n;
    cin >> n;
    
    ull ans = 0;
    for(ll a = 1; a*a*a <= n; a++) {
        for(ll b = a; b*b <= n/a; b++) {
            for(ll c = b; c <= n/(a*b); c++) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
