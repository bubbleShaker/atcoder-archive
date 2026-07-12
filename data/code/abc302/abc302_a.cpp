#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll A, B;
    cin >> A >> B;
    
    ll ans = (A / B);
    
    if(A%B) ans++;
    
    cout << ans << endl;
    
    return 0;
}
