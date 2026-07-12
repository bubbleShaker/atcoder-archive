#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> b(m);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int ans = 0;
    for(int i = 0; i < m; i++){
        ans += a[b[i]];
    }
    cout << ans << endl;
    return 0;
}
