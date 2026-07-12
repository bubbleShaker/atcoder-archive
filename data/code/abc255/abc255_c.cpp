#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    if(d < 0) {
        a = a+d*(n-1);
        d = -d;
    }
    if(d == 0) {
        cout << abs(x-a) << endl;
        return 0;
    }
    ll i = (x-a)/d;
    auto f = [&](ll i) {
        if(i < 0) i = 0;
        if(i >= n) i = n-1;
        return a+d*i;
    };
    cout << min(abs(x-f(i)), abs(x-f(i+1))) << endl;
    return 0;
}
