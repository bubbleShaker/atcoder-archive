#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    ll x_mi = (ll)(x1 - sqrt(5));
    ll x_ma = (ll)(x1 + sqrt(5));
    ll y_mi = (ll)(y1 - sqrt(5));
    ll y_ma = (ll)(y1 + sqrt(5));
    
    for(ll x3 = x_mi; x3 <= x_ma; x3++){
        for(ll y3 = y_mi; y3 <= y_ma; y3++){
            if(pow((x1 - x3), 2.0) + pow((y1 - y3), 2.0) != 5) continue;
            if(pow((x2 - x3), 2.0) + pow((y2 - y3), 2.0) != 5) continue;
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}