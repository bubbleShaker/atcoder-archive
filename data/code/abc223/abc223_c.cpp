#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    
    long double t = 0;
    for(int i = 0; i < N; i++) t += (long double)A[i] / B[i];
    t /= (long double)2;
    
    long double ans = 0;
    
    for(int i = 0; i < N; i++){
        long double tt = (long double)A[i] / B[i];
        if(t - tt > 0){
            t -= tt;
            ans += A[i];
        }else{
            ans += B[i]*t;
            break;
        }
    }
    
    cout << fixed << setprecision(20);
    cout << ans << endl;
    return 0;
    
}