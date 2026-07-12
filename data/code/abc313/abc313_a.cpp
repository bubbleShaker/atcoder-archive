#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    int ma = 0;
    int co = 0;
    for(int i = 0; i < n; i++){
        ma = max(ma, p[i]);
    }
    for(int i = 0; i < n; i++){
        if(p[i] == ma){
            co++;
        }
    }
    if(ma == p[0]){
        if(co > 1){
            cout << 1 << endl;
            return 0;
        }
        cout << 0 << endl;
        return 0;
    }
    int ans = ma - p[0] + 1;
    cout << ans << endl;
    return 0;
}