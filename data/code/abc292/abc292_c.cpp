#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(int x){
    ll res = 0;
    for(int i = 1; i*i <= x; i++){
        if(x%i != 0) continue;
        int j = x/i;
        if(i == j) res++;
        else res += 2;
    }
    return res;
}

int main(void){
    int N;
    cin >> N;
    
    ll ans = 0;
    
    for(int x = 1; x < N; x++){
        int y = N-x;
        ans += f(x)*f(y);
    }
    
    cout << ans << endl;
    
    return 0;
}
