#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    ll syou = sum / n;
    ll amari = sum % n;
    vector<ll> ave(n);
    for(int i = 0; i < n; i++){
        ave[i] = syou;
    }
    for(int i = n-1; i > n-1-amari; i--){
        ave[i] += 1;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll sa = abs(a[i]-ave[i]);
        ans += sa;
    }
    ans /= (ll)2;
    cout << ans << endl;
    return 0;
}
