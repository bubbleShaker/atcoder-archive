#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, K;
    cin >> N >> K;
    
    set<ll> s;
    
    for(int i = 0; i < N; i++){
        ll A;
        cin >> A;
        s.insert(A);
    }
    
    int ans;
    for(int i = 0; i < K; i++){
        ans = i;
        if(!s.count(i)) break;
        if(i == K-1) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}
