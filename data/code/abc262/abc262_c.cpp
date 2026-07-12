#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(int n){
    ll sum = 0;
    for(int i = n-1; i >= 1; i--){
        sum += (ll)i;
    }
    return sum;
}

int main(void){
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    ll t = 0;
    for(int i = 1; i <= N; i++){
        int tmp = i;
        if(tmp == A[i]) t++;
    }
    
    ll ans = calc(t);
    
    for(int i = 1; i <= N; i++){
        int tmp = A[i];
        if(tmp != i){
            if(A[tmp] == i){
                ans++;
                A[tmp] = -1;
                A[i] = -1;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
    
}